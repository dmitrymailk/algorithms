## Modern C++ Concurrency: Get the most out of any machine

- Created: 2022-01-14 20:01
- Tags: #cpp #concurrency #cpp20
- Link: [main page](https://www.educative.io/courses/modern-cpp-concurrency-in-practice-get-the-most-out-of-any-machine)
- Момент появления:
- Summary:

## C++11 and C++14: The Foundation

- tags

---

С появлением с++11, с++ приобрел multithreading library and a memory model. В этой библиотеке есть основные строительные блоки, такие как atomic variables, threads, locks и condition variables.

Multithreading появился еще в с++11, он имел хорошую memory model и standardized threading interface.

Основой multithreading является хорошая memory model, которая имела следующие свойства

- Atomic operations - операции, которые могут выполняться без прерывания
- Частичный порядок операций: последовательность операций, порядок которых нельзя менять.
- Видимые эффекты операций: гарантирует, что операции с shared variables видны в других threads.

Модель памяти C++ была вдохновлена ее предшественницей: моделью памяти Java. Однако, в отличие от модели памяти Java, C++ позволяет нам нарушить ограничения sequential consistency, которая является поведением atomic operations по умолчанию.

Sequential consistency дает две гарантии

1.  Инструкции программы выполняются в порядке исходного кода
2.  Существует глобальный порядок для всех операций на всех threads

---

## Atomics

- tags #atomic

---

C++ имеет набор простых atomic типов данных: booleans, characters, numbers, and pointers. Вы можете определить свой собственный atomic тип данных с помощью шаблона класса std::atomic. Atomics устанавливает ограничения синхронизации и упорядочения, которые также могут выполняться для non-atomic типов. Стандартизированный thread интерфейс является ядром параллелизма в C++.

---

## Threads

- tags #thread

---

std::thread представляет собой независимую unit выполнения программы. Executable unit, которы стартует мгновенно получает рабочий пакет который называется callable unit. Callable unit может быть функцией, function object или lambda function.

Создатель thread ответственен за его lifecycle. Executable unit нового thread заканчивает свою работу после окончания вызова.
Либо создатель ждет пока thread не закончит свою работу, к примеру мы назовем его t, тогда функция (**t.join()**) ожидает thread пока он не закончит свою работу. Или пока создатель thread не сделает detach процесса (**t.detach()**). Наш thread является joinable если над ним не совершались операции **t.join()** или **t.detach()**, joinable thread завершает свою работу путем вызова std::terminate в своем конструкторе, что означает что эта программа завершает свою работу.

Thread над которым совершили операцию **t.detach()** называется daemon thread, потому что он выполняется в background. **std::thread** это variadic template, что означает что он может получать произвольное количество аргументов по copy или reference.

---

## Shared Data

- tags #shared_data

---

Можно управлять процессом доступа к shared variable, если больше чем один thread используют эту переменную, причем она не является константой. Чтение и запись shared variable в одно и тоже время называется data race. Что влечет за собой непредсказуемое поведение. Управление доступом к shared variable осуществляется при помощи mutexes и locks в C++.

---

## Mutexes

- tags #mutex

---

Mutex (mutual exclusion (взаимное исключение)) гарантирует что только один thread имеет доступ к shared variable в любой момент времени. C++ имеет пять различных mutex, они могут блокироваться рекурсивно, предварительно и с или без ограничений по времени. Даже mutex могут делить один итот же lock.

---

## Locks

- tags #locks

---

Мне следует инкапсулировать mutex в lock, чтобы освободить mutex автоматически. lock воплощает RAII idiom что означает что он привязывает время жизни mutex к его собственному. C++ имеет **std::lock_guard** для простых случаев и **std::unique_lock**/**std::shared_lock** для расширенных вариантов использования, таких как explicit locking или unlocking of the mutex.

---

## Thread-safe Initialization of Data

- tags #thread_safe

---

Если shared data только для чтения, тогда достаточно инициализировать thread-safe. В с++ это можно достигнуть несколькими способами

- constant expression
- static variable with block scope
  - вызов функции **std::call_once** с флагом **std::once_flag**

---

## Thread Local Data

- tags #thread_local

---

Объявление переменной thread-local делает ее доступной только в конкретном thread, время жизни этой переменной ограничено временем работы данного thread.

---

## Condition Variables

- tags #сondition_мariables

---

Condition variables позволяют синхронизировать thread путем сообщений. Один thread может выступать отправителем, пока другой thread может принимать его сообщения, причем блок может ждать сообщение от другого thread и только потом продолжать своё выполнение. Condition variables используют для producer-consumer workflows. Condition variables могут быть как отправителями, так и получателями, но правильное их использование довольно сложно, поэтому для этого используют другой подход.

---

## Tasks

- tags #cpp_task

---

Tasks очень распространены при использовании thread. Пока мы детально должны описывать процесс создания thread, task просто процесс который мы запускаем. C++ runtime автоматически обработает простом случае **std::async** lifetime of the task

Tasks как каналы данных между двумя точками связи. Они могут включить thread-safe взаимодействие между threads, передавая между ними данные. Эти данные могут быть каким-то значением, exception или обычным уведомлением. Кроме **std::async** с++ имеет class templates **std::promise** и **std::future** которые дают больше контроля над task.

---

## Examples

1. Calculating the sum of a vector
2. Thread-Safe Initialization of a Singleton
3. Ongoing Optimization with CppMem

## 1. Calculating the sum of a vector

- tags #cpp_vector

---

Как можно быстрее всего вычислить сумму всех элементов в **std::vector**? Я заполню вектор числами, равномерно распределенными от 1 до 10, причем этих чисел будет сто миллионов. Задача состоит в том чтобы посчитать их сумму разными способами.

### 1 Способ loop

- tags #loop

---

```cpp
// calculateWithLoop.cpp

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

constexpr long long size = 100000000;

int main()
{
    std::cout << std::endl;
    std::vector<int> randValues;
    randValues.reserve(size);

    // random values
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();

    unsigned long long sum = {};
    for (auto n : randValues)
        sum += n;

    const std::chrono::duration<double> dur =
        std::chrono::steady_clock::now() - sta;

    std::cout << "Time for mySumition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for mySumition 0.809787 seconds
Result: 550035865
```

Но выполнять такие простые операции как сложение над вектором через цикл некорректно, для этого есть встроенные функции из STL.

---

### 2 Cпособ accumulate

- tags #accumulate

---

```cpp
// calculateWithStd.cpp

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

constexpr long long size = 100000000;

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    // random values
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();

    const unsigned long long sum = std::accumulate(randValues.begin(),
                                                   randValues.end(), 0);
    const std::chrono::duration<double> dur =
        std::chrono::steady_clock::now() - sta;

    std::cout << "Time for mySumition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for mySumition 0.73079 seconds
Result: 550035865
```

На linux машинах не должно быть разницы между циклом и **std::accumulate**, но на windows машинах разница ощутима.

---

### 3 Protection with Locks

- tags #lock #mutex

---

Если я закрою доступ к переменной через lock, тогда я хочу знать 2 вещи

- Насколько дорога синхронизация lock без contention(соревнования)?
- Насколько быстрой может быть lock в оптимальном случае?

```cpp
// calculateWithLoop.cpp

#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <mutex>

constexpr long long size = 100000000;

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    // random values
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();

    std::mutex myMutex;
    unsigned long long sum = {};
    for (auto i : randValues)
    {
        std::lock_guard<std::mutex> myLockGuard(myMutex);
        sum += i;
    }

    const std::chrono::duration<double> dur =
        std::chrono::steady_clock::now() - sta;

    std::cout << "Time for mySummation " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for mySummation 3.6954 seconds
Result: 550035865
```

Из работы кода можно сделать вывод что работа кода увеличивается если использовать **std::lock_guard**, вместо **std::accumulate**.

---

### 4 Protection with Atomics

- tags #atomic

---

Такие же вопросы и насчет atomics.

- Насколько дорога синхронизация atomic?
- Насколько быстрой может быть atomic без contention(соревнования)?
- Что производительнее использовать atomics или locks?

```cpp
// calculateWithAtomic.cpp

#include <atomic>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

constexpr long long size = 100000000;

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    // random values
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    std::atomic<unsigned long long> sum = {};
    std::cout << std::boolalpha << "sum.is_lock_free(): "
              << sum.is_lock_free() << std::endl;
    std::cout << std::endl;

    auto sta = std::chrono::steady_clock::now();

    // код выше должен вывести true, значит что atomic не использует lock
    // это важно, иначе мы не увидим разницы между lock и atomic
    // также тут мы используем оператор +=
    for (auto i : randValues)
        sum += i;

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;

    sum = 0;
    sta = std::chrono::steady_clock::now();

    // а тут мы используем функцию fetch_add, вместо оператора +=
    // fetch_add означает что мы точно знаем что выполняем операцию в одном thread
    for (auto i : randValues)
        sum.fetch_add(i);

    dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
sum.is_lock_free(): true

Time for addition 1.61241 seconds
Result: 550035865

Time for addition 1.29985 seconds
Result: 550035865
```

По итогу можно сделать выводы что

- atimic в 12-50 раз медленее на linux и windows чем обычное использование **std::accumulate** без синхронизации
- atomics в 2-3 раза быстрее на linux и windows чем locks
- **std::accumulate** хорошо оптимизирован под windows

---

### 5 Using std::lock_guard

- tags #lock_guard #lock #threads

---

Использование shared variable для суммирования с 4 threads не очень оптимально. synchronization overhead перевешивает преимущества производительности.
Поэтому попытаемся ответить на следующие вопросы:

- как отличаются производительности в суммировании при использовании locks и atomic?
- как отличаются производительности в суммировании при использовании multithread execution и **std::accumulate**?
  Самый простой способ сдедлать thread-safe суммирование это использовать **std::locks_guard**

```cpp
// synchronisationWithLock.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

std::mutex myMutex;

void sumUp(unsigned long long &sum, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    for (auto it = beg; it < end; ++it)
    {
        std::lock_guard<std::mutex> myLock(myMutex);
        sum += val[it];
    }
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    unsigned long long sum = 0;
    const auto sta = std::chrono::steady_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for addition 4.1601 seconds
Result: 549996948
```

**std::lock_guard** нужен чтобы защитить shared variable **sum**. Узкое место программы это переменная **sum**, так как очень тяжело ее синхронизировать при помощи **std::lock_guard**. Тогда сразу напрашиватся решение, заменить тяжеловесный lock на atomic.

### 6 Atomic Variable

- tags #atomic #atomic_variable #relaxed_semantic

---

Теперь мы будем использовать только atomics, то есть сделаем переменную **sum** atomic variable.

```cpp
// synchronisationWithAtomic.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

std::atomic<unsigned long long> sum = {};

void sumUp(std::atomic<unsigned long long> &sum, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    for (auto it = beg; it < end; ++it)
    {
        sum += val[it];
    }
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for addition 5.46418 seconds
Result: 549996948
```

Автор утверждает что эта версия должна работать быстрее, но на моём компьютере эта версия работает намного медленнее. Также стоит заметь что вместо оператора сложения **+=** можно использовать функцию **fetch_add**, эта функция не дает никакого прироста производительности в сравнении с оператором **+=**, но зато она позволяет использовать **relaxed semantic**

---

### 7 fetch_add Method with Relaxed Semantic

- tags #relaxed_semantic #fetch_add

---

Теперь нам нужно добавить только **sum.fetch_add(val[it], std::memory_order_relaxed)** в цикл суммирования

```cpp
// synchronisationWithFetchAddRelaxed.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

std::mutex myMutex;
std::atomic<unsigned long long> sum = {};

void sumUp(std::atomic<unsigned long long> &sum, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    for (auto it = beg; it < end; ++it)
    {
        sum.fetch_add(val[it], std::memory_order_relaxed);
    }
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for addition 5.62143 seconds
Result: 549996948
```

Примечание: автор утверждает что у него этот метод дает наибольшуют производительность, у меня же наблюдается значительное уменьшение.

Поведение по умолчанию для atomics это sequential consistency. Это утверждение верно для сложения, приравнивания и **fetch_add** метода, но мы можем оптимизировать это еще лучше. Мы переписали суммирования на relaxed semantic **sum.fetch_add(val[it], std::memory_order_relaxed**. Relaxed semantic это — самая слабая модель памяти и, следовательно, конечная точка моей оптимизации.

Relaxed semantic хорошо подходит для нашего случая, так как она дает нам 2 гарантии:

- каждое сложение с импользованием **fetch_add** будет сделано с использованием atomic
- и threads будут синхронизированны при вызове join

---

### 8 Using Local Variable

- tags #local_variable #threads

---

Теперь мы минимизируем синхронизацию между threads и будем использовать local variables. Для этого мы будем использовать **std::lock_guard** и atomic с sequential consistancy и relaxed semantic

```cpp
// localVariable.cpp

#include <mutex>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

std::mutex myMutex;

void sumUp(unsigned long long &sum, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    unsigned long long tmpSum{};
    for (auto i = beg; i < end; ++i)
    {
        tmpSum += val[i];
    }
    std::lock_guard<std::mutex> lockGuard(myMutex);
    sum += tmpSum;
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    unsigned long long sum{};
    const auto sta = std::chrono::system_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    const std::chrono::duration<double> dur =
        std::chrono::system_clock::now() - sta;

    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for addition 0.127536 seconds
Result: 549996948
```

Теперь мы вначале вычисляем локальную переменную, а затем прибавляем ее результат к глобальной.

---

### 9 Atomic Variable with Sequential Consistency

- tags #sequential_consistency #atomic_variable

---

Теперь мы заменим глобальную non-atomic переменную **sum** на atomic.

```cpp
// localVariableAtomic.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

std::mutex myMutex;
std::atomic<unsigned long long> sum = {};

void sumUp(std::atomic<unsigned long long> &sum, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    unsigned int long long tmpSum{};

    for (auto i = beg; i < end; ++i)
    {
        tmpSum += val[i];
    }
    sum += tmpSum;
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for addition 0.150771 seconds
Result: 549996948
```

---

### 10 Atomic Variable with Relaxed Semantic

- tags #relaxed_semantic #atomic_variable

---

Мы можем использовать вместо стандартной модели памяти использовать relaxed semantic. При использовании relaxed semantic суммирование может происходить даже не по порядку.

```cpp
// localVariableAtomicRelaxed.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

std::mutex myMutex;
std::atomic<unsigned long long> sum = {};

void sumUp(std::atomic<unsigned long long> &sum, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    unsigned int long long tmpSum{};

    for (auto i = beg; i < end; ++i)
    {
        tmpSum += val[i];
    }
    sum.fetch_add(tmpSum, std::memory_order_relaxed);
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for addition 0.134366 seconds
Result: 549996948
```

Как и ожидалось нет никакой разницы между использованием **std::lock_guard** или atomic с sequential consistency или relaxed semantic.

Стоит упомянуть что thread-local данные это особый вид локальных данных, он живет не пока завершится функция, а пока завершится thread.

---

### 11 Using Thread Local Data

- tags #local_data #thread

---

Thread-local данные принадлежат thread в котором они были созданы.

```cpp
// threadLocalSummation.cpp

#include <atomic>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

// thread local data
thread_local unsigned long long tmpSum = 0;

void sumUp(std::atomic<unsigned long long> &sum, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    for (auto i = beg; i < end; ++i)
    {
        tmpSum += val[i];
    }
    sum.fetch_add(tmpSum, std::memory_order_relaxed);
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    std::atomic<unsigned long long> sum{};
    const auto sta = std::chrono::system_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    const std::chrono::duration<double> dur =
        std::chrono::system_clock::now() - sta;

    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}
```

```console
Time for addition 0.641264 seconds
Result: 549996948
```

---

### 12 Using Tasks

- tags #cpp_task

---

Tasks в с++ способны делать всю работу что мы делали выше без синхронизации. Суммирование выполняется отдельно в каждом thread и финальный результат помещается в main thread.

```cpp
// tasksSummation.cpp

#include <chrono>
#include <future>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

void sumUp(std::promise<unsigned long long> &&prom, const std::vector<int> &val,
           unsigned long long beg, unsigned long long end)
{
    unsigned long long sum = {};
    for (auto i = beg; i < end; ++i)
    {
        sum += val[i];
    }
    prom.set_value(sum);
}

int main()
{

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    std::promise<unsigned long long> prom1;
    std::promise<unsigned long long> prom2;
    std::promise<unsigned long long> prom3;
    std::promise<unsigned long long> prom4;

    auto fut1 = prom1.get_future();
    auto fut2 = prom2.get_future();
    auto fut3 = prom3.get_future();
    auto fut4 = prom4.get_future();

    const auto sta = std::chrono::system_clock::now();

    std::thread t1(sumUp, std::move(prom1), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::move(prom2), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::move(prom3), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::move(prom4), std::ref(randValues), thi, fou);

    unsigned long long sum = fut1.get() + fut2.get() + fut3.get() + fut4.get();

    std::chrono::duration<double> dur = std::chrono::system_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << std::endl;
}
```

```console
Time for addition 0.12898 seconds
Result: 549996948
```

### Сумма вектора - заключение

- tags #memory_bound

---

Нет никакой разницы в обычном суммировании циклом и функцией **std::accumulate**, но это правда к наиболее оптимизированным версиям. В оптимизированной версии компилятор использует SIMD (SSE or AVX) инструкции для сложения.

Использовать shared variable можно только с синхронизацией, но синхронизация потоков это очень ресурсоемкая операция, необходимо уменьшить ее использование как можно больше.

Использование thread-local данных только в 2 раза быстрее чем простое использование однопоточного кода с функцией **std::accumulate**. Это удивило автора, он ожидал прирост в 4 раза, причем его ядра не были даже полностью загружены. Но причина тому проста, процессоры не могут получать данные достаточно быстро из памяти, это называется **memory bound**

---

---
