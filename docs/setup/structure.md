# Structure 

This repository combines the source code, the documentation and the editor setup at once. Therefore it is crucial to understand the directories structure. The following `folders` are most likely to be changed by future developers:  

## /src

Here all every line of `C++` code is put. Within this directory there are sub-folders in order to keep a tidy structure. When adding a new folder for a new structural element, give this folder a meaningful name. 

## /scripts

This folders intention is to store essential scripts which facilitate coding. Therefore all types of scripts can be put here (`python`, `shell` etc.).

## /docs 

The `/docs` folder (like the name implies) stores every line of `markdown` code. In the future the intention of this project is to integrate a automatic doc generation tool like [Doxygen](https://www.doxygen.nl/index.html). Doxygen allows the developer to write `doc-strings` which can be compiled into readable `markdown` code.