<h2 align="center">
CS3560 Homework Assignment: Static Analysis Tools (100 Points)<br/>
CppCheck or Infer <br/>
Due date: Please refer to the entry on Blackboard
</h2>

The purpose of this assignment is to help students learn to use static analysis tools to identify program defects. In particular, students will have an opportunity to use CppCheck (https://github.com/danmar/cppcheck).

In this assignment, you will be performing the following tasks.

1. Using cppcheck to check part of the cppcheck source code and part of the doxygen source code.
2. Compiling and performing static analysis on a souce code from your pair.
3. Identify the differences between compiler and static analysis tool.

You can choose to use [Facebook's Infer](https://fbinfer.com/) instead of cppcheck for this HW assignment.

## Reading Assignment

1. Read [this section of C++ Best Practices by Jason Turner](https://github.com/cpp-best-practices/cppbestpractices/blob/master/02-Use_the_Tools_Available.md#compilers).
2. Read/skim through [Cppcheck's manual](https://cppcheck.sourceforge.io/manual.pdf)
3. (optional) [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

## Required Software Tools

- C/C++ Compiler
- GNU Make (on Windows it can be from MSYS2, Make for Windows http://gnuwin32.sourceforge.net/packages/make.htm, or make inside WSL2)
- cppcheck
- doxygen
- (optional) IDE of your choice (Eclipse, Visual Studio, Visual Studio Code, XCode, or JetBrains’ Clion, etc.)


## Step 1 - Form a team of two

If you have not done already, form **a team of two** for this assignment. If there is a team with only one student, you can join them. If you already have a team, you can create a new one for both of you (and make sure that both of you join at the same time otherwise other may join).

Even though this is a pair assignment, your report must be in your work.

## Step 2 - Clone the repository

This assignment uses a feature in Git call Submodule. To clone this repository, you need a special command

```console
git clone --recurse-submodules <HTTP-url-or-SSH-url>
```

If you already clone this repository without `--recurse-submodules`, you can run the following command instead.

```console
git submodule init
git submodule update
```

To verify that the submodules initialization work, `source/cppcheck` and `source/doxygen` should have files in them.

## Step 3 - Check in your own source code

Each student must identify a large C/C++ project done in the past and check in the code in a separate folder in the repo. A good candidate of the large project is your project from CS2401. Once a project is identified, add source code of the project into the repository under `source/<your-email-handle>` folder. For example, `source/kc555014/`.

Make sure that your project can be built with just a command `make` (or with CMake). Once everything is ready push out your commit.

If your pair does not check in the source code and the due date is approaching, you perform the tasks with
any open-source project instead. If you don't have any prior C/C++ project, use an open-source project instead.

## Step 4 - Compile each other's project

1. Normally compile the project checked-in by your teammate in step 3.
2. Compile the project again, but this time utlize some of the flags listed in the article by Jason Turner
   in the reading assignment list.

Make note of the output from the compiler in both steps. Does the additional flags surface any problems in the codebase?
Keep this result in mind when compare result between compiler and static analysis tools.

## Step 5 - Perform static analysis

In each step, explore the option of cppcheck (or the tool of your choice). The instructions here are leaning toward cppcheck.
Other tools may behave differently. **Take some screenshots** to support your discussion in the write-up.

### 5.1 On cppcheck

1. cd into `source/cppcheck`.
2. Run cppcheck against any of the the following folders: `cli/`, `lib/`, `oss-fuzz/`, `externals/`, `gui/`. Running cppcheck aginst the entire codebase will take too long. Some folders will take long time to be checked than the other, so if you already got interesting problem to talk about you can stop the check.
3. Take note of any interesting problem, found by the tool, you want to discuss.

### 5.2 On doxygen

1. cd into `source/doxygen`.
2. Pick a `.cpp` files from `source/doxygen/src`, run cppcheck on the file.
3. Repeat step 2 until you found interesting problems reported by the tool you want to discuss.

### 5.3 On your partner's codebase

Use cppcheck (for C/C++), lint (for C), splint (for C), or another static analyzer to check the other student's project. Note all warnings/errors. **Take screenshots**. (If you don’t have splint on your Linux system, use `apt-get` to install it. Splint doesn’t check C++ code. If your project is in C++, use only cppcheck.)

Take note of any interesting problem, found by the tool, you want to discuss.

## Submission

**Individually and independently**, submit a PDF file with the following
sections and content to Blackboard. This report must be your own work.

### Section A - Static analysis on the codebases

For each codebase, use these questions to start your discussion:

- What problem did you found?
- Discuss the reason you pick the problem, what impact do you think it has on the codebase, what do you
  found interesting about the problem.
- If no problems are found, show that you try your best to configure the static analysis tool. E.g. what
  option did you pick to provide correct setting for the codebase, did you provide `--language=c++` to
  cppcheck when checking a C++ codebase?, did you try `--enable=all` for cppcheck?

### Section B - Compiler vs. static analysis

Discuss the result of the flags you tried in step 4. In particular compare it with the result you got from
step 5.3.

- Does the normal compilation (without any special flags listed in the article) surface any problem in the codebase?
- Disscuss the ability of the compiler vs. the static analysis tool in finding problems in the codebase.
- Did compiler and static analysis tool discover the same set of problems?
- What flags did you ended up using for step 4? Why did you pick said flags?

## Appendix A - Tips

- CppCheck Manual: http://cppcheck.sourceforge.net/manual.pdf
- Example output during the cppcheck installation on MacOS https://www.dropbox.com/s/fw7666rik2uzhtu/Sample-CppcheckInstallationOnMac.txt?dl=0  
- Example output during the cppcheck installation on Linux https://www.dropbox.com/s/f32q0a0dop2u4lk/Sample-Cppcheck_install_steps.docx?dl=0

## Appendix B - How to compile cppcheck

You may also want to consult [cppcheck's documentation](https://github.com/danmar/cppcheck/?tab=readme-ov-file#compiling) on how to compile cppcheck.

### On EECS's Linux Server

All dependencies should already be installed on EECS's linux server (for your own linux machine or WSL, make sure that
`flex` and `bison` are installed), so we can perform each
of the following steps.

```console
cd source/cppcheck
mkdir build
cd build
cmake ..
cmake --build .
```

The executable can then be found in `bin` folder.

### On Microsoft Windows 11

You may want to use WSL instead of this approach.

1. Install required software

  - CMake: It can be download from https://cmake.org/download/. Make sure to check "Add cmake to PATH".
  - Visual Studio 2022: Download the "Community" version from https://visualstudio.microsoft.com/downloads/. During the
    installation, make sure you select "Desktop development with C++".

2. Generate Makefiles and compile

```console
cd source/cppcheck
mkdir build
cmake -S . -B build
cmake --build build
```

The executable can be found in `bin/Debug` folder.

## Appendix C - How to compile doxygen

You may also want to consult [Doxygen's documentation](https://www.doxygen.nl/manual/install.html) on how to compile Doxygen.

### On EECS's Linux Server

All dependencies should already be installed on EECS's linux server, so we can perform each
of the following steps.

```console
cd source/doxygen
mkdir build
cmake -G "Unix Makefiles" -S . -B build
cmake --build build
```

The executable should be in `bin` folder if the compilation is successful.

Note: This compilation may take a long time.

### On Microsoft Windows 11

You may want to use WSL instead of this approach.

1. Install required software. If any is already installed, skip it.

  - CMake: It can be download from https://cmake.org/download/. Make sure to check "Add cmake to PATH".
  - winflexbison: Download `win_flex_bison-2.5.25.zip` from the "Assets" of a release at https://github.com/lexxmark/winflexbison/releases.
    Then extract all files to a folder. Rename the `win_flex.exe` to `flex.exe`, and rename `win_bison.exe` to `bison.exe`. Add this
    folder to the environment variable named `PATH`.
  - Visual Studio 2022: Download the "Community" version from https://visualstudio.microsoft.com/downloads/. During the
    installation, make sure you select "Desktop development with C++".

2. Generate Makefiles and compile

Form start menu, open "Developer PowerShell for VS 2022", and type the following commands in this terminal. Make sure
to `cd` into your repository first.

```console
cd source/doxygen
mkdir build
cd build
cmake -G "NMake Makefiles" ..
nmake
```

The executable should be in the `bin` folder.

Note: This compilation may take a long time.

## Appendix C - Rubric

Total Point: 100 points

### A - Static analysis of codebases (50 points)

- (+25) Via the discussion, a student shows that they can identify problems reported by the static analysis tool.
- (+20) Via the screenshot and discussion, students show that they can properly utilze a static analysis tool.
- (+5) List of four unique problems are identified and provided. If no problem are found, student present sufficent
  evidence that they did attempt to configure the tool for the codebase.

### B - Compiler vs. static analysis (50 points)

- (+25) Via screenshots and discussion, students demonstrate the ability to use C/C++ built-in checks.
- (+25) Students show understanding of the different between compiler and static analysis tool.
