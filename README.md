# Example project python API for C/C++

## Description
This code illustrates how C/C++ modules can be called from Python. See https://docs.python.org/3/extending/extending.html
Installation instructions for Ubuntu


## Prerequisites

gcc, python, python-dev

### Install gcc

To install gcc:

```bash
sudo apt update
sudo apt install build-essential
sudo apt-get install manpages-dev
```

Validate:

```bash
gcc --version
```

### Install python

To install python:

```bash
sudo apt-get install python3.x
```

Replace x with latest release

### Install python-dev

```bash
sudo apt install python-dev
```

## Installation

Clone this repo:

```bash
clone https://github.com/ivanhkingman/extending-python-with-C
```

Build the shared library file:

```bash
python setup.py build
```

## Use

Navigate to the folder where the shared library file is located:

```bash
cd build
cd temp.linux-x86_64-x.x
```
Replace x.x according to your version.

Start interactive Python session and test:
```bash
Python
>> import hello
>> hello.say_hello("your_name_here")
```


