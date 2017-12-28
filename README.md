# get_next_line
Read the next line from the given file descriptor.

This is roughly similar to how `getline` behaves.

##### Prototype:
`int  get_next_line(const int fd, char **line);`

### Cool tidbits about this:
* Uses `BUFF_SIZE`, which is defined in `get_next_line.h` to determine read size. It will work with any value `> 0`, given there is heap memory available in that quantity.
* Uses a linked list so that it can handle multiple file descriptors. Each list item corresponds to a file descriptor. See the `t_fdb` struct.
* Uses only 1 constant variable, which is a pointer to the first item in the list of file descriptors. 
