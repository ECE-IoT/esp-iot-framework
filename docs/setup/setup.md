# Getting started

## First steps

### Requirements

Make sure that `python 3.8` or higher and `pip3` are installed on your PC. Next ensure that you have installed a capable text editor like VS Code (any other editor should work fine as long a you can use the necessary plugins for this project).

!!! note 

    If your are using VS Code you can install some very helpful **extensions**. Those extension are **optional** but will simplify writing code. Check out the extensions tab further below. 

### Dependencies

The project requires some python packages which are essential f.e. for embedded development (PlatformIO) or for building docs (Mkdocs). You can install them by using `pip3`. Make sure that you are in the projects `root` folder

=== "Linux / macOS"

    ```shell
    pip3 install -r requirements.txt
    ```

=== "Windows"

    ``` shell 
    python3 -m pip install -r requirements.txt
    ```

After the installation you should be able to use `mkdocs` and `pio`, which are the `CLI` tools for the documentation and platformIO. 



## Extensions

This list contains some good extensions which make developing code way easier. As always, this is just a short summary of what's possible. If you want to dig deeper into Extensions and Tools for VS Code, visit their [docs](https://code.visualstudio.com/docs/editor/codebasics). 

* [PlatformIO](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
* [C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
* [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
* [C/C++ Themes](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes)
* [Python](https://marketplace.visualstudio.com/items?itemName=ms-python.python)
* [Pylance](https://marketplace.visualstudio.com/items?itemName=ms-python.vscode-pylance) 