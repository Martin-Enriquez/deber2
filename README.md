MARTIN SEBASTIAN ENRIQUEZ JIMENEZ

C++ TEORIA NRC:2684

Transformacion de divisas

El programa funciona a partir de un menú principal que permite al usuario seleccionar entre diferentes modos de operación. A partir de esta selección, el sistema ejecuta el flujo correspondiente para realizar conversiones de divisas y generar estadísticas.

Primero, el programa solicita al usuario ingresar los códigos de la divisa base y la divisa cotizada. Se realiza una validación para asegurar que los códigos ingresados correspondan a las opciones permitidas (USD, EUR o JPY). Si el usuario ingresa un código inválido, el programa vuelve a solicitar el dato hasta que sea correcto.

Una vez definidas las divisas, el usuario debe ingresar la tasa de cambio. 

Posteriormente, el usuario introduce el monto base que desea convertir. Este valor también es validado para asegurar que sea numérico y mayor que cero.

Con estos datos, el programa realiza la conversión mediante la fórmula:

conversion = monto_base × tasa_de_cambio

El resultado se muestra al usuario con formato numérico, incluyendo dos decimales y separador de miles para mejorar la legibilidad.

Dependiendo del modo de operación seleccionado, el programa puede repetir este proceso para múltiples conversiones o acumular los resultados para calcular estadísticas como total acumulado, promedio, monto mínimo y monto máximo.

El flujo del programa continúa hasta que el usuario decide regresar al menú principal o finalizar la ejecución.
