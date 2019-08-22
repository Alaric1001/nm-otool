# nm-otool
Toy implementation of nm & otool bsd commands. The general idea was to learn how a binary file work and how to parse it properly.

These tools only support mach-o files.
## Build & run
Just run `make`, it will generate `ft_nm` and `ft_otool`.

#### Tests
You can test nm with some system binaries by launching `make test_all`. It will assert there is no output difference between my implementation and the current system implementation.
Tests will take some time to complete!

## ft_nm
#### Usage
`./ft_nm -uUrpj [FILE ...]`
#### Options
```
-u     Display only undefined symbols.
-U     Don't display undefined symbols.
-r     Sort in reverse order.
-p     Don't sort; display in symbol-table order.
-j     Just display the symbol names (no value or type).
```

## ft_otool
#### Usage
`./ft_otool -td [FILE ...]`
#### Options
```
-t     Display the contents of the (__TEXT,__text) section.
-d     Display the contents of the (__DATA,__data) section.
```

**This project is a student exercise and is by no mean intended to be used for real**
