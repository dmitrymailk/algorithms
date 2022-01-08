int main()
{
  // это значит что мы выделили память под указатель, который будет отвечать за
  // 5 integers и один указатель который будет отввечать за один integer
  int a[5], *p;

  int sum, i;

  for (sum = a[0], i = 1; i < 5; i++)
    sum += a[i];

  for (sum = *a, i = 1; i < 5; i++)
    sum += *(a + i);

  for (sum = *a, p = a + 1; p < a + 5; p++)
    sum += *p;
  // это одно и тоже
  /*
  Note that a+1 is a location of the next cell of the array a so that a+1 is equivalent to
  &a[1]. Thus, if a equals 1020, then a+1 is not 1021 but 1022 because pointer arithmetic
  depends on the type of pointed entity. For example, after declarations
  char b[5];
  long c[5];
  and assuming that b equals 1050 and c equals 1055, b+1 equals 1051 because one
  character occupies 1 byte, and c+1 equals 1059 because one long number occupies
  4 bytes. The reason for these results of pointer arithmetic is that the expression c+i
  denotes the memory address c+i*sizeof(long).
  */
  int n = 5;
  // выделяем память под 5 integers, но что важно делаем это динамически
  p = new int[n];
  // если мы хотим удалить из памяти целый массив, то нам нужно написать
  delete[] p;
}