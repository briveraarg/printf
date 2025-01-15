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

------
### Cositas a tener en cuenta

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


Cuando se utilizan números negativos con el especificador `%u`, el valor se interpreta como un entero sin signo, aprovechando la representación de complemento a dos. Por ejemplo:

  ```c
  printf("%u\n", -1);
  ```
  En un sistema de 32 bits, esto imprimirá `4294967295`, que es el valor máximo de un entero sin signo de 32 bits.
  
- **Complemento a dos:** Es una forma de representar números negativos en binario. Un número negativo como `-1` en complemento a dos se obtiene invirtiendo todos los bits de su representación en binario positivo y sumándole 1.
En el caso de un entero de 32 bits:

  ```plaintext
  1 en binario: 00000000 00000000 00000000 00000001 (32 bits)
  
  -1 en binario: 11111111 11111111 11111111 11111111 (32 bits)
  Interpretable como 4294967295 en entero sin signo.
  ```

En complemento a dos, `-1` se obtiene invirtiendo todos los bits de `1` (es decir, `00000000 00000000 00000000 00000001`), y luego sumando 1 al resultado.
Esto es porque en un número sin signo, todos los bits se suman, y el valor `11111111 11111111 11111111 11111111` corresponde a `4294967295`.

#### ¿Por qué es importante el complemento a dos?

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

### Uso de Hexadecimal en C

El sistema hexadecimal es una representación numérica en base 16. Es ampliamente utilizado en programación, especialmente para representar colores, direcciones de memoria, y valores binarios de manera más compacta y legible.

#### ¿Qué es el sistema hexadecimal?

El sistema hexadecimal usa 16 símbolos para representar valores: `0-9` para los valores numéricos del 0 al 9, y `A-F` (o `a-f`) para los valores 10 a 15. Este sistema es muy útil en programación porque cada dígito hexadecimal representa exactamente 4 bits, o un "nibble", lo que hace más fácil trabajar con números binarios y direcciones de memoria.

#### Ventajas de usar hexadecimal:

1. **Compacto**: En lugar de escribir largos números binarios, podemos usar valores más compactos en hexadecimal.
2. **Facilidad de conversión**: Un dígito hexadecimal se corresponde con 4 bits, lo que facilita la conversión entre binario y hexadecimal.
3. **Uso en memoria y direcciones**: Es comúnmente usado en programación de bajo nivel para representar direcciones de memoria o registros de hardware.

### Ejemplo de uso de hexadecimal en C:

En C, podemos utilizar el especificador de formato `%x` o `%X` en `printf` para imprimir números en formato hexadecimal.

```c
#include <stdio.h>

int main()
{
    int colorRojo = 0xFF0000; // Rojo
    int colorVerde = 0x00FF00; // Verde
    int colorAzul = 0x0000FF;  // Azul

    // Imprimir los colores en formato hexadecimal
    printf("Color Rojo: %#X\n", colorRojo);    // Imprime 0xFF0000
    printf("Color Verde: %#X\n", colorVerde);  // Imprime 0x00FF00
    printf("Color Azul: %#X\n", colorAzul);    // Imprime 0x0000FF

    return (0);
}
```

#### Uso común de hexadecimal en programación:
Representación de colores: Los colores en aplicaciones gráficas se representan comúnmente en formato hexadecimal. Cada color se descompone en tres componentes: rojo, verde y azul (RGB), y cada uno se representa como un número hexadecimal entre 00 (sin intensidad) y FF (máxima intensidad).

Direcciones de memoria: En programación de sistemas o programación a nivel de hardware, las direcciones de memoria y registros se representan en hexadecimal porque facilita la visualización y manejo de direcciones largas.

Codificación de datos binarios: El sistema hexadecimal es útil cuando se necesita trabajar con datos binarios de manera eficiente, ya que cada byte (8 bits) puede representarse con dos dígitos hexadecimales.

#### Conversión entre binario y hexadecimal:

De binario a hexadecimal: Los números binarios se agrupan de 4 en 4 bits (nibbles) y luego se convierten a un solo dígito hexadecimal. Por ejemplo, el número binario 1111 es igual a F en hexadecimal.
De hexadecimal a binario: Cada dígito hexadecimal se convierte en un grupo de 4 bits binarios. Por ejemplo, F en hexadecimal se convierte en 1111 en binario.

#### ¿Por qué es útil en programación?
El uso de hexadecimal permite una representación más compacta y legible de los números binarios, especialmente cuando se trabajan con valores grandes, direcciones de memoria o datos a nivel de hardware. Esto hace que el desarrollo de sistemas y la programación de bajo nivel sea más eficiente.

------
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
   
4. Usa `ft_printf` como lo harías con `printf`:

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

Si tienes dudas o preguntas sobre cómo funcionan estos conceptos, no dudes en preguntar. Preguntar está bien, lo tonto es no preguntar.
