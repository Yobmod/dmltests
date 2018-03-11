const MAXLINE: int = 1000 # maximum input line length

proc getline(line: char, maxline: int): int
proc copy(line: char, fromm: char): void
#int getline(char line[], int maxline);
#void copy(char to[], char from[]);

# print the longest input line
proc main(): int =
  var len: int = getline(line, MAXLINE)
  var max: int = 0
  var line[MAXLINE]: char
  var char longest[MAXLINE]: char

  while len > 0
  if len > max:
	max = len
	copy(longest, line)
  if max > 0:
	echo longest
  return 0
# main()
# {
# int len; /* current line length */
# int max; /* maximum length seen so far */
# char line[MAXLINE]; /* current input line */
# char longest[MAXLINE]; /* longest line saved here */
# max = 0;
# while ((len = getline(line, MAXLINE)) > 0)
# if (len > max) {
# max = len;
# copy(longest, line);
# }
# if (max > 0) /* there was a line */
# printf("%s", longest);
# return 0;
# }

# getline: read a line into s, return length
proc getline(s: char, lim: int): int =
  var c: int
  var i: int

x  for i in countup(0, lim-1):
    c = getchar()
	if c = EOF or c='\n':
		break
	else:

  for i in range(0, lim-1):
    c = getchar()
	if c !=EOF && c!='\n':
	  inc(i)
	  s[i] = c
    elif c == '\n':
      s[i] = c
	  inc(i)
	  inc(i)
    elif c == '\0':
	  s[i] = '\0';
      return i;


int getline(char s[],int lim)
{
int c, i;
for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
s[i] = c;
if (c == '\n') {
s[i] = c;
++i;
}
s[i] = '\0';
return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
int i;
i = 0;
while ((to[i] = from[i]) != '\0')
++i;
