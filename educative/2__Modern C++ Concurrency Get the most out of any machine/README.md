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

- tags #atomics

---

C++ имеет набор простых atomic типов данных: booleans, characters, numbers, and pointers. Вы можете определить свой собственный atomic тип данных с помощью шаблона класса std::atomic. Atomics устанавливает ограничения синхронизации и упорядочения, которые также могут выполняться для non-atomic типов. Стандартизированный thread интерфейс является ядром параллелизма в C++.

---

## Threads

- tags #threads

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

- tags #cpp_tasks

---

Tasks очень распространены при использовании thread. Пока мы детально должны описывать процесс создания thread, task просто процесс который мы запускаем. C++ runtime автоматически обработает простом случае **std::async** lifetime of the task

Tasks как каналы данных между двумя точками связи. Они могут включить thread-safe взаимодействие между threads, передавая между ними данные. Эти данные могут быть каким-то значением, exception или обычным уведомлением. Кроме **std::async** с++ имеет class templates **std::promise** и **std::future** которые дают больше контроля над task.

---
