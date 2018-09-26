
# Comandos basicos V

*Deshacer multiples cambios en el repositorio:*

`git  reset  --soft <id_commit >`

`git  reset  --mixed  <id_commit >`

`git  reset  --hard <id_commit >`

*Listar archivos que git no controla:*

`git  clean  -n`

*Eliminar archivos que git no controla*:

`git  clean  -f`

*Listar el contenido del repositorio de git:*

`git ls-tree  master`

`git ls-tree  master ^^^`

`git ls-tree  master ~3`