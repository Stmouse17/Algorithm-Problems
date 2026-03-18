# VSCODE 教程

### 1.进入文件目录

`cd D:\Program\ACM\xxx`

### 2.编译

#### (1)单文件

`g++ main.cpp -o main`

#### (2)多文件

**一次性**

`gcc src/main.c src/add.c -Iinclude -o main`

**分步骤**
**【1】编译（生成 .o）**

`gcc -c src/main.c -Iinclude -o build/main.o`
`gcc -c src/add.c -Iinclude -o build/add.o`

**【2】链接**

`gcc build/main.o build/add.o -o main`

### 3.运行

Bash 

`.\main`

cmd/PowerShell

`./main`

cmd
`main < input.txt`

PowerShell

`Get-Content input.txt | .\main`

### 4.调试

```javascript
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug C++",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/main.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "externalConsole": true,
      "MIMode": "gdb",
      "miDebuggerPath": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing",
          "text": "-enable-pretty-printing"
        }
      ]
    }
  ]
}
```

**编译修改**
`g++ -g main.cpp -o main`
`gcc -g src/main.c src/add.c -Iinclude -o main`

```shell
gcc -g -c src/main.c -Iinclude -o build/main.o
gcc -g -c src/add.c -Iinclude -o build/add.o

gcc build/main.o build/add.o -o main
```

