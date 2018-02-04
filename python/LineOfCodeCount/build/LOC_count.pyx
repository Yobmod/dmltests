import os
from typing import List, Dict, Optional, Tuple, Union  # , Any, NewType, get_type_hints
import cython

def xyz(a: cython.longlong, b: cython.long, c: str) -> cython.int:
	d: cython.longlong = (a * b)*(10 * b)
	e: cython.int = len(str(d) + c)
	return e

def countlines(
	start: str,
	lines: int=0,
	header: bool=True,
	begin_start: Optional[str]=None) -> int:

	def print_header(header: bool=header) -> None:
		if header:
			print('{:>10} |{:>10} | {:<20}'.format('ADDED', 'TOTAL', 'FILE'))  # print column titles
			print('{:->11}|{:->11}|{:->20}'.format('', '', ''))  # print line
	print_header()
	ext_tup = ('.py', '.pyx', '.c', '.cpp', '.js', '.jsx', '.ts', '.tsx')
	exc_list: List[str] = ["vendor", "dist", "build", "energenie"]

	for thing in os.listdir(start):
		thing = os.path.join(start, thing)
		if os.path.isfile(thing) and thing.endswith(ext_tup):
			if begin_start is not None:
				reldir_of_thing = '.' + thing.replace(begin_start, '')
			else:
				reldir_of_thing = '.' + thing.replace(start, '')
			with open(thing, 'r', encoding="utf8") as f:
				newlines = f.readlines()
				num_lines: int = len(newlines)
				lines += num_lines

				print('{:>10} |{:>10} | {:<20}'.format(num_lines, lines, reldir_of_thing))

	for thing in os.listdir(start):
		thing = os.path.join(start, thing)
		if os.path.isdir(thing):
			if any(x in thing for x in exc_list) is False:
				lines = countlines(thing, lines, header=False, begin_start=start)
	return lines


def pyLines(directory: str) -> int:
	exc_list: List[str] = ["vendor", "dist", "build", "energenie", "htmlcov", ]
	py_lines = 0
	for thing in os.listdir(directory):
		thing = os.path.join(directory, thing)
		if os.path.isfile(thing):
			with open(thing, 'r') as f:
				if thing.endswith(('.py', '.pyx', )):
					newlines = f.readlines()
					py_lines = py_lines + len(newlines)
		elif os.path.isdir(thing) and not any(x in thing for x in exc_list):
				lines = pyLines(thing)
				py_lines = py_lines + lines
	return py_lines


def jsLines(directory: str) -> int:
	js_lines = 0
	exc_list: List[str] = ["vendor", "dist", "build", "energenie"]
	for thing in os.listdir(directory):
		thing = os.path.join(directory, thing)
		if os.path.isfile(thing):
			with open(thing, 'r') as f:
				if thing.endswith('.js') or thing.endswith('.jsx'):
					newlines = f.readlines()
					js_lines = js_lines + len(newlines)
		elif os.path.isdir(thing) and not any(x in thing for x in exc_list):
				lines = jsLines(thing)
				js_lines += lines
	return js_lines


def cLines(directory: str) -> int:
	c_lines = 0
	exc_list: List[str] = ["vendor", "dist", "build", "energenie"]
	for thing in os.listdir(directory):
		thing = os.path.join(directory, thing)
		if os.path.isfile(thing):
			with open(thing, 'r', encoding="utf8") as f:
				if thing.endswith('.c') or thing.endswith('.cpp'):
					newlines = f.readlines()
					c_lines = c_lines + len(newlines)
		elif os.path.isdir(thing) and not any(x in thing for x in exc_list):
				lines = cLines(thing)
				c_lines = c_lines + lines
	return c_lines


def ext_tuple(file_type: Union[str, Tuple[str, ...]]) -> Tuple[str, ...]:
	"""Takes filetype(s) as string or tuple. Filetype should be '.xyz'
	or name of language. Outputs tuple of file extentions"""
	ext_tup: Tuple[str, ...] = ()
	file_type_dict: Dict[str, Tuple[str, ...]] = {
		"python": ('.py', '.pyi', ),
		"py": ('.py', '.pyi', ),
		"cython": ('.pyx', ),
		"cy": ('.pyx', ),
		"javascript": ('.js', '.jsx', ),
		"js": ('.js', '.jsx', ),
		"typescript": ('.ts', '.tsx', ),
		"ts": ('.ts', '.tsx', ),
		"text": ('.txt', '.md', '.doc', 'docx', ),
		"c": (".c", ".cpp", ".c++"),
	}
	if isinstance(file_type, str):
		file_type = file_type.lower()
		if file_type.startswith("."):
			ext_tup = (file_type, )
		elif file_type in file_type_dict:
			ext_tup = file_type_dict[file_type]
		else:
			raise ValueError("filetype should be in form '.xyz' or 'python', 'javascript', 'c' ")
	elif isinstance(file_type, tuple):
		for x in file_type:
			each_tup: Tuple[str, ...] = ext_tuple(x)
			ext_tup = ext_tup + each_tup
	else:
		raise TypeError("filetype must be a string or tuple of strings")
	return ext_tup


def exclude_list(black_list: Union[str, List[str]]=None) -> List[str]:
	exc_list: List[str] = ["vendor", "dist", "build", "htmlcov", ]
	if black_list:
		if isinstance(black_list, list):
			exc_list += black_list
		elif isinstance(black_list, str):
			exc_list.append(black_list)
		else:
			raise TypeError("Excluded subfolders should be list of strings")
	return exc_list


def typeLines(
	fold_dir: str,
	file_type: Union[str, Tuple[str, ...]],
	black_list: Union[str, List[str]]=None) -> int:
	"""Takes fold_dir as abs or rel path string. Takes filetype as string or
	tuple, converted by ext_tuple() to file extensions, then LOC counted in matching
	files in fold_dir and subfolders. Excluded subfolders in from exclude_list()"""
	ext_tup = ext_tuple(file_type)
	exc_list = exclude_list(black_list)
	lines = 0
	for thing in os.listdir(fold_dir):
		thing = os.path.join(fold_dir, thing)
		if os.path.isfile(thing) and thing.endswith(ext_tup):
			with open(thing, 'r') as f:
				newlines = f.readlines()
				lines += len(newlines)
		elif os.path.isdir(thing) and not any(x in thing for x in exc_list):
			fold_lines = typeLines(thing, file_type)
			lines += fold_lines
	return lines

# textList = ['a.tif','b.jpg','c.doc','d.txt','e.tif'];
# filteredList = filter(lambda x:x.endswith('.tif'), textList)


def typeLines_print(
	fold_dir: str,
	black_list: Union[str, List[str]]=["tests", "mock"]) -> Dict[str, int]:
	# pyLOC = pyLines(fold_dir)
	# jsLOC = jsLines(fold_dir)
	# cLOC = cLines(fold_dir)

	pyLOC2 = typeLines(fold_dir, "python", black_list=black_list)
	jsLOC2 = typeLines(fold_dir, "javascript", black_list=black_list)
	cLOC2 = typeLines(fold_dir, "c", black_list=black_list)
	iniLOC2 = typeLines(fold_dir, ".INI")
	# print(str(pyLOC) + "py", str(jsLOC) + "js", str(cLOC) + "c")
	# return {"py": pyLOC, "js": jsLOC, "c": cLOC, }
	print(str(pyLOC2) + "py", str(jsLOC2) + "js", str(cLOC2) + "c", str(iniLOC2) + "ini")
	return {"py": pyLOC2, "js": jsLOC2, "c": cLOC2, }


if __name__ == "__main__": 		# pragma: no cover
	fold_dir = os.getcwd()
	countlines(fold_dir)
	typeLines_print(fold_dir)
# 	print(typeLines(fold_dir, ("py", "js", "c",), black_list="tests"))

# print(get_type_hints(countlines))
