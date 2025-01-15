# ft\_printf

`ft_printf` es una reimplementación de la función estándar `printf` en C. Este proyecto forma parte del currículo de 42 y tiene como objetivo reforzar conocimientos sobre el manejo de funciones variádicas, manipulación de strings, y formatos de salida en C.

### Características

- Soporta los siguientes especificadores de formato:
  - `%c`: Imprime un carácter.
  - `%s`: Imprime una cadena de caracteres.
  - `%p`: Imprime una dirección de memoria.
  - `%d`/`%i`: Imprime un número entero con signo.
  - `%u`: Imprime un número entero sin signo.
  - `%x`: Imprime un número en hexadecimal en minúsculas.
  - `%X`: Imprime un número en hexadecimal en mayúsculas.
  - `%%`: Imprime un signo de porcentaje.

### Detalles de Implementación

- `ft_printf` utiliza funciones variádicas (`va_list`, `va_start`, `va_arg`, `va_end`) para manejar un número variable de argumentos. Las funciones variádicas permiten a una función recibir un número indeterminado de argumentos. Por ejemplo:

  ```c
  #include <stdarg.h>
  #include <stdio.h>

  void ejemplo_variadico(const char *formato, ...)
  {
      va_list args;
      va_start(args, formato);
      int numero;
    
      while (*formato)
      {
          if (*formato == 'd')
          {
              numero = va_arg(args, int);
              printf("%d\n", numero);
          }
          formato++;
      }
      va_end(args);
  }

  int main(void)
  {
      ejemplo_variadico("ddd", 1, 2, 3);
      return (0);
  }
  ```

  Salida:

  ```plaintext
  1
  2
  3
  ```

- El comportamiento original de `printf` puede variar según el sistema operativo:

  - En Linux, cuando se pasa un puntero nulo (`NULL`) a `%p`, la salida será `(nil)`.
  - En otros sistemas, esta representación puede cambiar.

- Cuando se utilizan números negativos con el especificador `%u`, el valor se interpreta como un entero sin signo, aprovechando la representación de complemento a dos. Por ejemplo:

  ```c
  printf("%u\n", -1);
  ```

  En un sistema de 32 bits, esto imprimirá `4294967295`, que es el valor máximo de un entero sin signo de 32 bits.

- **Complemento a dos:** Es una forma de representar números negativos en binario. Un número negativo como `-1` en complemento a dos se obtiene invirtiendo todos los bits de su representación en binario positivo y sumándole 1.
- En el caso de un entero de 32 bits:

  ```plaintext

  1 en binario: 00000000 00000000 00000000 00000001 (32 bits)
  
  -1 en binario: 11111111 11111111 11111111 11111111 (32 bits)
  Interpretable como 4294967295 en entero sin signo.
  ```

En complemento a dos, `-1` se obtiene invirtiendo todos los bits de `1` (es decir, `00000000 00000000 00000000 00000001`), y luego sumando 1 al resultado.

Esto es porque en un número sin signo, todos los bits se suman, y el valor `11111111 11111111 11111111 11111111` corresponde a `4294967295`.

---

### ¿Por qué es importante el complemento a dos?

El complemento a dos es un sistema utilizado para representar números negativos en binario. Permite realizar operaciones aritméticas sin necesidad de operaciones separadas para números negativos, facilitando la implementación en hardware y software.


```c
#include <stdio.h>

int main()
{
    printf("%u\n", -3);  // Se interpreta como un entero sin signo
    printf("%u\n", 3);   // Se imprime el valor 3 como un entero sin signo
    return (0);
}
```

Salida :
```c
4294967293
3
```

## Archivos

- **Makefile**: Archivo para compilar el proyecto. Se utilizan las siguientes flags para una compilación robusta:
  - `-Wall`: Habilita todos los warnings.
  - `-Werror`: Considera los warnings como errores.
  - `-Wextra`: Habilita warnings adicionales.
- **ft\_printf.h**: Archivo de cabecera que contiene las declaraciones de funciones y macros necesarias.
- **ft\_printf.c**: Implementación principal de la función `ft_printf`.
- **ft\_putnbr\_base.c**: Funciones auxiliares para manejar la conversión de números a diferentes bases.
- **ft\_write\_char.c**: Funciones para imprimir caracteres y cadenas.
- **ft\_write\_number.c**: Funciones para imprimir números en diferentes formatos.

### Uso

1. Incluye el archivo de cabecera `ft_printf.h` en tu proyecto.
2. Compila tu programa junto con la librería generada:
   ```bash
   cc -Wall -Werror -Wextra -o tu_programa tu_programa.c libftprintf.a
   ```
3. Usa `ft_printf` como lo harías con `printf`:
   ```c
   #include "ft_printf.h"

   int main(void)
   {
       ft_printf("Hola, %s! Tienes %d mensajes.\n", "Brenda", 42);
       return (0);
   }
   ```

### Ejemplo

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Caracter: %c\n", 'A');
    ft_printf("Cadena: %s\n", "Hola mundo");
    ft_printf("Puntero: %p\n", (void *)0x1234abcd);
    ft_printf("Entero: %d\n", 42);
    ft_printf("Unsigned: %u\n", -1);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

Salida esperada:

```plaintext
Caracter: A
Cadena: Hola mundo
Puntero: 0x1234abcd
Entero: 42
Unsigned: 4294967295
Hexadecimal: ff
```


Si tienes dudas o preguntas sobre cómo funcionan estos conceptos en C o sobre la representación de números en otros sistemas, no dudes en preguntar.

