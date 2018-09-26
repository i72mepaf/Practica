# Tutorial de Git Parte 1
## Configuración básica
### Nombre del administrador:
`git config --global user.name "Felipe Mérida Palacios"`
### Correo electrónico
`git config --global user.email i72mepaf@uco.es`
### Editor de texto
`git config --global core.editor "atom"`
### Color de la interfaz:
`git config --global color.ui true`
### Listado de la configuración:
`git config --list`
## Comandos básicos I
### Iniciar repositorio en un directorio
`git init`
### Agregar cambios al area de staging:
`git add`
### Validar cambios en el repositorio:
`git commit -m "Mensaje"`
### Hacer los dos pasos anteriores en uno:
`git commit -am "Mensaje"`
### Historial de commits:
`git log`
## Comandos básicos II
### Ayuda del listado anterior:
`git help log`
### Listar los 5 commits más recientes:
`git log -n 5`
### Listar los commits desde una fecha:
`git log --since =2018-09-25`
### Listar los commits por autor:
`git log --author ="Felipe"`
### Ver cambios en el directorio:
`git status`
## Comandos básicos III
### Ver diferencia entre ficheros en el directorio y el repositorio de git:
`git diff`
### Ver diferencia entre ficheros en el *staging* y el repositorio:
`git diff --staged`
### Eliminar archivos