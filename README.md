# libft

At 42, students aren't allowed to use most standard library functions, save for critical ones like malloc, free, write and read.
In order to get around this, students recode these functions, using the aforementioned allowed functions where they're necessary.
Libft is a library of these recoded functions, to be expanded and used in future projects as needed.

In addition to the required functions, I also coded several bonus functions. These include:

* ft_is_whitespace - this function returns true if the specified character is a whitespace character, ie, spaces, tabs, newlines, etc. Useful for ft_strtrim and ft_strsplit.

* ft_split_by_function - this takes in a char* string and a function pointer, and splits it into a 2d array of strings. The function pointer adds more versatility - For example, I can specify a function like ft_is_whitespace, and split the string by whitespace.

* ft_split_by_delims - this takes in two char *strings - a string to split, and a null-terminated list of delimiters. This allows for a bit more specificity than split_by_function

* ft_trim_by_delims - this function removes the specified delimiters from the beginning and end of the input string.

* ft_trim_by_function - this function does something similar to ft_trim_by_delims, except it takes in a function pointer, and trims the characters that cause the function to return true.

* ft_strjoinfree - This function takes in two strings, allocates a new string, copies both old strings over, and frees the input strings. This is very useful for avoiding memory leaks in projects like Get_Next_Line and ft_printf.

* ft_find - this function searches for a substring in a string, and returns the index of said substring if it's found, or -1 if it isn't.

* ft_find_and_replace - this function implements find, searches an input string for a specified substring, and replaces all occurrences of it with another substring.

* ft_is_in - this function returns true if a specified character is found within a list of characters. Useful for printf.

* ft_countif - this function counts all instances of a character within a string, and returns the count.

* get_next_line - This function returns a line from a file descriptor, returning a different one every time it's called. This is a late addition that I added after completing the Get_Next_Line project. It's very useful in future projects.
