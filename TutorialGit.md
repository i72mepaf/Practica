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
~~~
git rm archivo
git commit -m "Mensaje"
~~~
### Mover o renombrar archivos
~~~
git mv Antiguo Nuevo
git commit -m "Mensaje"
~~~
## Comandos básicos IV
### Deshacer cambios con git:
`git checkout -- nombre_fichero`
### Retirar archivos del *staging*:
`git reset HEAD nombre_fichero`
### Complementar último committ:
`git commit --amend -m "Mensaje"`
### Recuperar version de un chero de commit antiguo:
`git checkout <id_commit > -- nombre_archivo`
### Revertir un commit:
`git revert <id_commit >`

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

*Log en una línea:*

`git  log  --oneline`

*Log con los tres últimos commits en una línea:*

`git  log  --oneline  -3`

*Examinar el contenido de un commit:*

`git  show <id >`

*Comparar un commit con el actual:*

`git  diff <id > nombre_archivo`

*Comparar dos commits:*

`git  diff id..id  nombre_archivo`

# Comandos Ramas I

*Ver listado de ramas:*

`git  branch`

*Crear una rama:*

`git  branch  nombre_rama`

*Cambiarnos a una rama:*

`git  checkout  nombre_rama`

*Crear una rama y moverse en un paso:*

`git  checkout  -b nombre_rama`

*Comparar ramas:*

`git  diff  nombre_rama .. nombre_rama`

*Ver ramas identicas a la actual:*

`git  branch  --merged`

*Renombrar ramas:*

`git  branch  -m nombre_antiguo  nombre_nuevo`

*Eliminar ramas*

`git  branch  -d nombre_rama`

`git  branch  -D nombre_rama`

*Integrar ramas a la actual:*

`git  merge  nombre_rama`

# Tutorial de Git parte 3
## Resto de comandos en las ramas y comandos en GitHub

1.**Almacenar cambios temporales**

* `git stash save "Mensaje"`

2.**Listar cambios**

* `git stash list`

3.**Ver contenido de un cambio temporal**

* `git stash show -p nombre_stash`

4.**Eliminar un cambio temporal**

* `git stash drop nombre_stash`

5.**Aplicar cambio del stash**

* `git stash apply nombre_stash`
* `git stash pop nombre_stash`

> A partir de ahora veremos comandos de GitHub

1.**Añadir repositorio remoto**

* `git remote add origin url`

2.**Ver repositorios remotos**

* `git remote -v`

3.**Eliminar repositorio remoto**

* `git remote rm origin`

4.**Añadir cambios del repositorio local al remoto**

* `git push -u origin master`

5.**Añadir cambios del repositorio remoto al local**

* `git pull`

6.**Ver branches remotos**

* `git branch -r`

7.**Ver todos los branches**

* `git branch -a`

8.**Clonar un repositorio**

* `git clone url`

> Branches remotos

**De un branch local a uno remoto**

*`git push`

**De un branch remoto a uno local**

*`git fetch origin`

*`git merge origin/master`

> En un solo comando

 *`git pull`

**Creacion de un branch local**

*`git push -u origin branch_remoto`

**Copiar**

*`git checkout -b local remoto`

**Eliminar**

*`git push origin --delete branch_remoto`
