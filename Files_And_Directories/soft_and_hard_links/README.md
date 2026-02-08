# soft and hard links
## softlinks (symbolic links)
- links to a file with data. Can also be created for directories.
- a file can contain more than one soft link.
- Permissions are not updated in a soft link.


```
ln -s <file_name> <soft_link_name>

example
ln -s myfile myfile1
```

## unlinking a soft link.
i) Delete the link file
```
    rm myfile1
```
ii) Unlink the file
```
unlink <soft_link_name>

example;
unlink myfile1

```

## hardlink
```
ln <filename> <hard_link_name>

```
