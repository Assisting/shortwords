# shortwords
Attempting to find the longest and shortest words to type. Inspired by [Matt Parker](https://www.youtube.com/@standupmaths)'s video, [Why the longest English word is PAPAL and SPA is the pointiest.](https://www.youtube.com/watch?v=Mf2H9WZSIyw)

I don't use C very often (and haven't in 10 years) and I'm sure it shows. Too many Stack Overflow discussions were consulted for me to list.

Uses, by default, the `popular.txt` wordlist from [dolph/dictionary](https://github.com/dolph/dictionary)

## Usage
`make shortwords`

This will create the executable, which you can then run. Note that the `popular.txt` wordlist provided has been altered from [the original version](https://github.com/dolph/dictionary/blob/master/popular.txt) by removing the trivial `aa` and `mm` entries.

Alternatively, you may edit the file the program will read from by changing the defines in the `main.c` file. You will need to modify the size define as well.

To clean up, run: `make clean`
