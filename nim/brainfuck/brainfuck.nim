import os

echo "Wilkommen im brainfuck"

let code =
    if paramCount() > 0: readFile paramStr(1)
    else: readAll stdin

echo code

var
  tape: seq[char] = newSeq[char]()
  codePos: int = 0
  tapePos: int = 0
  readLen: int = 1

proc run(skip: bool=false): bool =
    while tapePos >= 0 and codePos < code.len:
      if tapePos >= tape.len:
        tape.add '\0'

      if code[codePos] == '[':
          inc codePos
          let oldPos = codePos
          while run(tape[tapePos] == '\0'):
            codePos = oldPos
      elif code[codePos] == ']':
          return tape[tapePos] != '\0'
      elif not skip:
        case code[codePos]
        of '+': inc tape[tapePos]
        of '-': dec tape[tapePos]
        of '>': inc tapePos
        of '<': dec tapePos
        of '.': stdout.write tape[tapePos]
        of ',': discard stdin.readChars(tape, tapePos, readLen)
        else: discard

      inc codePos
      echo "codePos: ", codePos, " tapePos: ", tapePos

discard run()

# brainfuck.nim(35, 31)   Error: Type mismatch, got(int) but expected'Char = char'
