// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // para usar acentuação
#include <string.h> // para usar funções de string
#define MAX 100

// Função para o menu de operações
int menu1()
{
  int op;
  printf("Qual operação deseja fazer?\n");
  printf("1 - Soma\n2 - Subtração\n3 - Divisão\n4 - Multiplicação\n");
  scanf("%d", &op);
  return (op);
}

// Função para o menu de bases numéricas
int menu2()
{
  int op;
  printf("Em qual base voce quer calcular?\n");
  printf("1 - Numeros Binarios\n2 - Numeros Octais\n3 - Numeros Hexadecimais\n");
  scanf("%d", &op);
  return (op);
}

// Operações em binário
int somabit(int bit1, int bit2, int *vaium)
{
  int soma;

  soma = (bit1 + bit2 + *vaium) % 2;
  *vaium = (bit1 + bit2 + *vaium) / 2;

  return (soma);
}

void inverte(int vetor[MAX], int n)
{
  int i, aux;
  for (i = 0; i < n / 2; i++)
  {
    aux = vetor[i];
    vetor[i] = vetor[n - 1 - i];
    vetor[n - 1 - i] = aux;
  }
  return;
}

int somabinario(int num1[MAX], int i, int num2[MAX], int j, int soma[MAX + 1])
{

  int k, vaium;

  inverte(num1, i);
  inverte(num2, j);

  if (j > i)
  {
    for (k = i; k < j; k++)
    {
      num1[k] = 0;
    }
    i = j;
  }
  else
  {
    if (i > j)
    {
      for (k = j; k < i; k++)
      {
        num2[k] = 0;
      }
      j = i;
    }
  }

  vaium = 0;
  for (k = 0; k < i; k++)
  {
    soma[i - k] = somabit(num1[k], num2[k], &vaium);
  }
  soma[0] = vaium;

  return (i + 1);
}
int subtraibit(int bit1, int bit2, int *vemum)
{
  int subtrai;
  subtrai = bit1 - *vemum - bit2;
  if (subtrai < 0)
  {
    *vemum = 1;
    subtrai += 2;
  }
  else
  {
    *vemum = 0;
  }
  return subtrai;
}

int subtraibinario(int num1[MAX], int i, int num2[MAX], int j, int subtrai[MAX])
{
  int k, vemum;

  inverte(num1, i);
  inverte(num2, j);

  if (j > i)
  {
    for (k = i; k < j; k++)
    {
      num1[k] = 0;
    }
    i = j;
  }
  else
  {
    if (i > j)
    {
      for (k = j; k < i; k++)
      {
        num2[k] = 0;
      }
      j = i;
    }
  }
  vemum = 0;
  for (k = 0; k < i; k++)
  {
    subtrai[i - k - 1] = subtraibit(num1[k], num2[k], &vemum);
  }
  return i;
}

// Função para converter bin�rio para decimal
int binario(int bin)
{
  int total = 0, pot = 1;
  while (bin > 0)
  {
    total += bin % 10 * pot;
    bin = bin / 10;
    pot = pot * 2;
  }
  return total;
}

// Função para converter ocatal para decimal
int octal(int oct)
{
  int total = 0, pot = 1;
  while (oct > 0)
  {
    total += oct % 10 * pot;
    oct = oct / 10;
    pot = pot * 8;
  }
  return total;
}

// Função para converter hexadecimal para decimal
int hexadecimal(int hexa)
{
  int total = 0, pot = 1;
  while (hexa > 0)
  {
    total += hexa % 10 * pot;
    hexa = hexa / 10;
    pot = pot * 16;
  }
  return total;
}

// Função para converter decimal para hexadecimal
void hexdec(int decimal)
{
  char VALORHEX[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  int tdec;
  char hex[65];
  int i, resto;
  tdec = decimal;
  i = 0;
  while (tdec != 0)
  {
    resto = tdec % 16;
    hex[i] = VALORHEX[resto];
    tdec /= 16;
    i++;
  }
  hex[i] = '\0';
  printf("Resposta:\n%s", hex);
}

// Função para converter decimal para binário
void bindec(int num)
{
  int i, bin[7];
  for (i = 7; i >= 0; i--)
  {
    if (num % 2 == 0)
    {
      bin[i] = 0;
      num = num / 2;
    }
    else
    {
      bin[i] = 1;
      num = num / 2;
    }
  }
  printf("Resposta:\n");
  for (i = 0; i <= 7; i++)
  {
    printf("%d", bin[i]);
  }
}

// Função para converter decimal para octal
void octdec(int n)
{
  int resultado[15] = {};
  int i = 0, y = 0;

  if (n >= 8)
  {
    printf("Resposta:\n");

    while (n >= 8)
    {
      resultado[i++] = n % 8;
      n = n / 8;
    }
    resultado[i] = n;

    for (y = i; y >= 0; y--)
    {
      printf("%d", resultado[y]);
    }
    printf("\n");
  }
  else
  {
    printf("Resposta:\n%d\n", n);
  }
}

// Função principal
int main()
{
  setlocale(LC_ALL, "Portuguese");
  int op1, op2, num1, num2;
  op1 = menu1();
  op2 = menu2();
  // SOMA
  if (op1 == 1)
  {
    if (op2 == 1)
    {
      int num1[MAX], num2[MAX], soma[MAX + 1], i, j, k, l;
      printf("Digite um numero binario (com digitos separados por espaco). Para parar, digite um numero diferente de 0 e 1.\n");
      i = 0;
      do
      {
        scanf("%d", &num1[i]);
        i++;
      } while ((num1[i - 1] == 0 || num1[i - 1] == 1) && i < MAX);
      i--;
      printf("Digite outro numero binario (com digitos separados por espaco). Para parar, digite um numero diferente de 0 e 1.\n");
      j = 0;
      do
      {
        scanf("%d", &num2[j]);
        j++;
      } while ((num2[j - 1] == 0 || num2[j - 1] == 1) && j < MAX);
      j--;
      printf("Numero 1: ");
      for (k = 0; k < i; k++)
      {
        printf("%d", num1[k]);
      }
      printf("\n");
      printf("Numero 2: ");
      for (k = 0; k < j; k++)
      {
        printf("%d", num2[k]);
      }
      printf("\n");
      l = somabinario(num1, i, num2, j, soma);
      printf("Soma: ");
      for (k = 0; k < l; k++)
      {
        printf("%d", soma[k]);
      }
      printf("\n");

      return (0);
    }
    if (op2 == 2)
    {
      printf("Digite um numero: ");
      scanf("%d", &num1);
      printf("Digite outro numero: ");
      scanf("%d", &num2);
      octdec(octal(num1) + octal(num2));
    }
    if (op2 == 3)
    {
      printf("Digite um numero: ");
      scanf("%d", &num1);
      printf("Digite outro numero: ");
      scanf("%d", &num2);
      hexdec(hexadecimal(num1) + hexadecimal(num2));
    }
  }
  // Subtração
  if (op1 == 2)
  {
    if (op2 == 1)
    {
      int num1[MAX], num2[MAX], subtrai[MAX] = {0}, i, j, k, l;
      printf("Digite um numero binario (com digitos separados por espaco). Para parar, digite um numero diferente de 0 e 1.\n");
      i = 0;
      do
      {
        scanf("%d", &num1[i]);
        i++;
      } while ((num1[i - 1] == 0 || num1[i - 1] == 1) && i < MAX);
      i--;
      printf("Digite outro numero binario (com digitos separados por espaco). Para parar, digite um numero diferente de 0 e 1.\n");
      j = 0;
      do
      {
        scanf("%d", &num2[j]);
        j++;
      } while ((num2[j - 1] == 0 || num2[j - 1] == 1) && j < MAX);
      j--;
      printf("Numero 1: ");
      for (k = 0; k < i; k++)
      {
        printf("%d", num1[k]);
      }
      printf("\n");
      printf("Numero 2: ");
      for (k = 0; k < j; k++)
      {
        printf("%d", num2[k]);
      }
      printf("\n");
      l = subtraibinario(num1, i, num2, j, subtrai);
      printf("Subtracao: ");
      for (k = 0; k < l; k++)
      {
        printf("%d", subtrai[k]);
      }
      printf("\n");
    }

    if (op2 == 2)
    {
      printf("Digite um numero: ");
      scanf("%d", &num1);
      printf("Digite outro numero: ");
      scanf("%d", &num2);
      octdec(octal(num1) - octal(num2));
    }
    if (op2 == 3)
    {
      printf("Digite um numero: ");
      scanf("%d", &num1);
      printf("Digite outro numero: ");
      scanf("%d", &num2);
      hexdec(hexadecimal(num1) - hexadecimal(num2));
    }
  }
  // Divisão
  if (op1 == 3)
  {
    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("Digite outro numero: ");
    scanf("%d", &num2);
    if (op2 == 1)
    {
      bindec(binario(num1) / binario(num2));
    }
    if (op2 == 2)
    {
      octdec(octal(num1) / octal(num2));
    }
    if (op2 == 3)
    {
      hexdec(hexadecimal(num1) / hexadecimal(num2));
    }
  }
  // Multiplicação
  if (op1 == 4)
  {
    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("Digite outro numero: ");
    scanf("%d", &num2);
    if (op2 == 1)
    {
      bindec(binario(num1) * binario(num2));
    }
    if (op2 == 2)
    {
      octdec(octal(num1) * octal(num2));
    }
    if (op2 == 3)
    {
      hexdec(hexadecimal(num1) * hexadecimal(num2));
    }
  }
}
