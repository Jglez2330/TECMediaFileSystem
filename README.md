# TECMediaFileSystem
## Descripción del problema
Tec Media File System (TECMFS) es un sistema de archivos que se asemeja mucho a una base de datos NoSQL bajo un esquema RAID 5. El mismo se encuentra construido mediante una arquitecrura distribuida llamada "Share Disk Architecure", la misma tendrá los siguientes componentes:

### Disk Nodes
Los nodos disco se encargan de almacenar los datos del cliente (bytes) o paridad. En cada nodo disco se
instalará la aplicación llamada TECMFS-Disk, la misma recibirá los siguientes parámetros de configuración
mediante un archivo XML:

* IP/Port: Para comunicación con el Controller Node
* Path: Dirección en el file system de la máquina donde se guardaran los datos.

El TECMFS-Disk debe asegurarse que el Disk Node tenga un tamaño fijo y que los bloques que conformen el
Disk Node tengan todos el mismo tamaño (Ambos tamaños son definidos por cada grupo). Es decir, todos los
Disk Nodes que pertenezcan al RAID deben proveer el mismo tamaño de almacenamiento y el tamaño de los
bloques debe ser el mismo en todos los Disk Node. Para implementar el esquema RAID 5, se requieren 4 nodos
funcionales.
Cada bloque del disco contiene datos o información de seguridad.

### Controller Node
El controller node es un servidor (escrito en C++) que se encarga de la gestión del almacenamiento y lectura de
los datos en los nodos. Debe:
* Gestionar la distribución de los videos en el RAID, lo cual incluye almacenar videos en los discos que
forman parte del RAID y brindar la información almacenada con respecto a los videos. Para el almacenamiento 
debe definir una estructura que permita identificar dónde están almacenados los videos dentro del RAID y
almacenar metadata de los videos que permita realizar búsquedas posteriores
* Gestionar el cálculo de la paridad para permitir la tolerancia a fallos, lo cual incluye generar la
información de paridad y utilizar esta para la carga de los videos aun cuando se pierda algún disco del
RAID.
* Obtener del RAID la información correspondiente de los videos
* Proveer un mecanismo de streaming de los videos.
Al iniciar el controller node, se debe especificar el puerto de comunicación con los nodos y aplicaciones
externas. El controller tiene una interfaz JSON que permite:
* Agregar/Eliminar un nuevo video
* Agregar/Actualizar metadata (Fecha, Director, Descripción, Nombre, Duración, entre otros) a un video
existente
* Buscar un video por metadata
* Reproducir un video por streaming.
El formato de los mensajes es definido por cada grupo.
El controller node provee una interfaz sencilla donde se muestra el estado de cada bloque de cada nodo del
Raid.

#### Aplicación de prueba
Se debe implementar una aplicación denominada Odissey MediaPlayer. Es un reproductor de videos que
utilizar TECMFS-Disk para almacenar los videos. La aplicación permite subir videos al TECMFS-Disk, editar
metadata de los videos y reproducirlos mediantes streaming. Se debe mostrar los controles estándar para
reproducir, pausar, adelantar y devolver el video.
Odissey MediaPlayer permite buscar en la biblioteca de videos por cualquiera de los campos de la metadata de
los videos.
## Planificación y administración del proyecto
Todos los aspectos referentes a la planificación y administración del proyecto se pueden encontrar en la sección de [proyectos](https://github.com/Jglez2330/TECMediaFileSystem/projects) de este repositorio.
### Diagrama de Clases
![Imgur](https://i.imgur.com/5LIatrP.jpg)
## Estructuras de Datos Desarrollados
### Árbol Rojo-Negro
Es un tipo de árbol binario de busqueda auto balaceado. En este árbol cada nodo posee un bit que indica el color del nodo, este puede ser de color rojo o negro.

##### Este arbol posee las siguientes propoiedades:
- Cada nodo es rojo o negro
- El nodo raíz es negro
- Todas las hojas son negras
- Cualquier camino de un nodo a cualquiera de sus hijos posee la misma cantidad de nodos negros

En el proyecto programado se uso para poder realizar buscadas mas eficientes y rapidas de la metadata que se guarda de cada video.
## Algoritmos Desarrollados
### RAID 5
El RAID (Redundant Array of Inexpensive Disks) es un sistema de almacenamiento de datos que utiliza multiple discos entre los cuales se distribuyen los datos.

El RAID 5, consiste en dividir un archivo en (n - 1) discos, donde n es el numero de discos en el array, en el disco restante se almacena el resultado de realizar la operacion XOR (exclusive or) en los datos de cada disco con el disco adyacente. Este sistema permite la falla de un disco en un array de cuatro discos.

Para restaurar los datos se realiza la operacion XOR en cada uno de los discos con el disco vecino, el resultado se le vuelve aplicar la operacion XOR con el disco vecino, esta operacion se realiza hasta que ya no queden discos, esto permite obtener el disco faltante
