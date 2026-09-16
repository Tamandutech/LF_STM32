# Line Follower - STM32

## Getting started
### Linux
1. Install the dependencies
```bash
# On Fedora
sudo dnf install cmake clangd arm-none-eabi-gcc arm-none-eabi-g++ openocd gdb
```

```bash
# On Debian (and derivatives, like Ubuntu, Mint, PopOS, etc.)
sudo apt-get install cmake clangd gcc-arm-none-eabi openocd gdb
```

<details>
<summary>What are these packages?</summary>

  | Package | Purpose |
  |---|---|
  | `cmake` | Configures/manages the project build process. |
  | `clangd` | Provides code completion, navigation, and error checking for C/C++. |
  | `gcc-arm-none-eabi` or `arm-none-eabi-gcc`, `arm-none-eabi-g++` | Cross-compiler for building C/C++ programs for ARM microcontrollers (which is the case of our STM32 chip). |
  | `openocd` | Connects to, programs, and debugs microcontrollers through a debug probe. |
  | `gdb` | Debugger used to inspect and control a running program. |

</details>

2. Clone this repository
```bash
git clone https://github.com/Tamandutech/LF_STM32.git
```

### Windows
For Windows users, we recommend dual-booting to facilitate and speed up project execution, or using the Windows Subsystem for Linux.

1. On WSL, create a Debian instance and install the required tools:
```bash
sudo apt-get install cmake clangd gcc-arm-none-eabi gdb
```

2. Install `openocd` on Windows itself.

3.  Clone this repository
```bash
git clone https://github.com/Tamandutech/LF_STM32.git
```

## Important configurations
The project was designed to recognize the tools installed on your Linux system, and work without additional configurations. However, if you
- are facing problems (linter/clangd doens't work well, debug problems, etc);
- changing project settings;
- running on a non Linux environment.

Try checking the following configurations:

| File | Configurations |
|---|---|
| `.vscode/settings.json` | `clangd.path` and `clangd.arguments` (where you inform the path of your compiler for clangd) |
| `.vscode/launch.json` | All configurations for the debugger you use on VSCode |

> [!NOTE]
> If you change the microcontroller, you'll have to replace the `.svd` file. You can find it on the page of your microcontroller: [example](https://www.st.com/en/microcontrollers-microprocessors/stm32g474rc.html#cad-resources).

<details>
<summary><h2>Compile/flash from terminal</h2></summary>

  Although these functionalities should be automatically configured on VSCodium, you may want to run on the CLI, or simply understand how the process is done:

  ### For debugging
  Cofigure the project (you have to run this once):
  ```bash
  cmake --preset Debug
  ```

  Compile:
  ```bash
  cmake --build build/Debug
  ```

  If you want to clean:
  ```bash
  cmake --build build/Debug --target clean
  ```

  Flash:
  ```bash
  cmake --build build/Debug --target flash
  ```

  ### For release
  Cofigure the project (you have to run this once):
  ```bash
  cmake --preset Release
  ```

  Compile:
  ```bash
  cmake --build build/Release
  ```

  If you want to clean:
  ```bash
  cmake --build build/Release --target clean
  ```

  Flash:
  ```bash
  cmake --build build/Release --target flash
  ```

</details>


<details>
<summary><h2>Optional steps</h2></summary>

### Install STM32CubeMX
If you need to *reconfigure* or *regenerate* the code, you'll need to install [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html).

### Install STM32CubeIDE
If you want to use STM32CubeIDE as your single IDE to edit, compile or flash code, instead of previous options, follow these steps:

1. In STM32CubeIDE, go to File → STM32 Project Create/Import.
2. Under Import STM32 Project, select STM32 CMake Project, then click Next.
3. Enter a project name (`LF_STM32`) and select the source folder, then click Next.
4. Choose the correct STM32 MCU (`STM32G474RCTx`) and click Finish.

<!-- https://community.st.com/stm32cubeide-mcus-28/import-a-cmake-project-created-by-cubemx-into-cubeide-164539 -->

</details>











<!-- ## Alterações Necessárias Celeris Core v1

- Circuito de proteção de corrente inversa com interruptor não funcionou, usar somente mosfet com interruptor e manter conectores xt para não ocorrer ligações invertidas

- Corrigir leds no esquemáticos que ficaram com a pegada invertida

- Utilizar pino com pwm comum para leds endereçaveis (atualmente em pwm invertido)

- utilizar leds maiores (0805 exemplo) não tem necessidade de utilizar leds tão pequenos, apenas dificultam manutenção

- remover leds de pinos de programação, não tem necessidade de utilizar e podem eceder o limite de corrente do pino

- corrigir pull up/down no pino de boot do stm32
-->
