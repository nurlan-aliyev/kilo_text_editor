# Kilo Text Editor

Kilo is a small terminal-based text editor written in C. It runs directly in a terminal, uses raw keyboard input, and keeps the implementation in a single source file: `kilo.c`.

This project is based on [snaptoken's "Build Your Own Text Editor" tutorial](https://viewsourcecode.org/snaptoken/kilo/index.html), which guides the reader through building a version of antirez's Kilo editor from scratch. The tutorial and its authors deserve credit for the foundation and approach used here.

## Capabilities

- Open an existing text file from the command line
- Create a new unnamed buffer and save it with a filename
- Insert and delete text, including new lines
- Navigate with the arrow keys, Home, End, Page Up, and Page Down
- Search through the open file with wraparound and direction controls
- Display a status bar with the filename, line count, modified state, file type, and cursor position
- Warn before quitting when the buffer has unsaved changes
- Highlight C, C++, and header files based on their filename extension
- Highlight C/C++ keywords, strings, numbers, single-line comments, and multiline comments
- Expand tabs to an eight-column display width
- Adjust to the terminal window size

## Requirements

- A Unix-like operating system with a terminal that supports ANSI escape sequences
- A C compiler with C99 support
- `make`

The source uses POSIX terminal and file APIs such as `termios`, `ioctl`, and `unistd`, so it is intended for Linux and other Unix-like systems.

## Build

From the project directory, run:

```sh
make
```

This compiles `kilo.c` into the `kilo` executable with warnings enabled.

To remove the generated executable, run:

```sh
rm -f kilo
```

## Run

Open an existing file:

```sh
./kilo path/to/file.c
```

Start with an empty buffer:

```sh
./kilo
```

When an empty buffer is saved, Kilo prompts for a filename.

## Keyboard Shortcuts

| Key | Action |
| --- | --- |
| Arrow keys | Move the cursor |
| `Home` / `End` | Move to the beginning / end of the current line |
| `Page Up` / `Page Down` | Move by one screen |
| `Enter` | Insert a new line |
| `Backspace` / `Delete` | Delete text |
| `Ctrl-S` | Save the current file |
| `Ctrl-F` | Search for text; use the arrow keys to move between matches and `Enter` to finish |
| `Ctrl-Q` | Quit; press repeatedly when unsaved changes are present |
| `Esc` | Cancel an active search or save prompt |

## Project Structure

```text
kilo_text_editor/
├── kilo.c    # Editor implementation
├── Makefile  # Build command
└── README.md # Project documentation
```

## Credits and Further Reading

- [Build Your Own Text Editor](https://viewsourcecode.org/snaptoken/kilo/index.html) by snaptoken
- [antirez's Kilo editor](http://antirez.com/news/108), the original editor that inspired the tutorial

This is a learning project as well as a usable minimal editor. The tutorial is the best place to learn how the terminal handling, screen rendering, text editing, search, and syntax highlighting are built step by step.
