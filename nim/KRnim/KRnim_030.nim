const MAXLINE: int = 1000 # maximum input line length

proc getline(s: string, lim: int): int
proc copy(to: string, fromm: string): void
#int getline(char line[], int maxline);
#void copy(char to[], char from[]);

# print the longest input line
proc main(): void =
  var max: int = 0
  var line: string
  var longest: string
  var len: int = getline(line, MAXLINE)


  while len > 0:
   if len > max:
    max = len
    copy(longest, line)

   if max > 0:
    echo longest

# getline: read a line into s, return length
proc getline(s: string, lim: int): int =
  var c: char

  for i in countup(0, lim-1):
    c = s[i]
    if c == '\n':
        break
    elif c == '\0':
      break
    return i;


# copy: copy 'from' into 'to'; assume to is big enough
proc copy(to: string, fromm: string): void =
  var i: int = 0
  while to[i] == fromm[i] and fromm[i] != '\0':
    i += 1

main()
