from dacite import from_dict
from dcf import elem_ce_dict, ElemClass

from dataclasses import dataclass, asdict
import pickle
import json
# import ujson as json
import dill
import toml

from typing import Dict, Any

"""
json/toml:
    ✘ need to use dataclass.asdict()
    ✔ readable
    ✘ need to rehydrate dataclass (eg with Dacite)
pickle/dill:
    ✔ direct from dataclass (or any object)
    ✔ remembers methods
    ✘ not-readable
sqlite:
    ???
"""

print(f"CLASS {elem_ce_dict}")

print(f"DICT {elem_ce_dict.as_dict()}")

# elem_ce_json = json.dumps(elem_ce_dict) fails!
elem_ce_json = json.dumps(elem_ce_dict.as_typdict())
r = elem_ce_dict.as_typdict()['atomic_mass']
print(f"JSON {elem_ce_json}")


# elem_ce_toml2 = toml.dumps(elem_ce_dict) fails!
elem_ce_toml = toml.dumps(elem_ce_dict.as_dict())
print(f"TOML {elem_ce_toml}")


# pickle keeps methods after unpickling
elem_ce_pckl = pickle.dumps(elem_ce_dict)
print(f"PICKLE {str(elem_ce_pckl)}")

elem_ce_unpckl = pickle.loads(elem_ce_pckl)
print(f"UNPICKLE {elem_ce_unpckl}")
print(elem_ce_unpckl.as_dict())


# dill keeps methods after unpickling
elem_ce_dill = dill.dumps(elem_ce_dict)
print(f"DILL {str(elem_ce_dill)}")

elem_ce_undill = dill.loads(elem_ce_dill)
print(f"UNDILL {elem_ce_undill}")
print(elem_ce_undill.as_dict())


@dataclass
class Test():
    name: str
    content: ElemClass


testy = Test(name="try", content=elem_ce_dict)

# pickle keeps methods and works for nested class instances
# if you change something on the instance, is it saved?
testy_pckl = pickle.dumps(testy)
print(f"PICKLE {str(testy_pckl)}")

testy_unpckl = pickle.loads(testy_pckl)
print(f"UNPICKLE {testy_unpckl}")
testy_unpckl.content.as_dict()

# use asdict to convert data to json string,
# #then rehydrate the a class instance with the unpacked json.loads
testy_json = json.dumps(asdict(testy))
print(f"JSON {testy_json}")
testy_unjson: Dict[str, Any] = json.loads(testy_json)

t2 = Test(**testy_unjson)
print(f"REHYDRATED_JSON {t2}")
t3 = from_dict(Test, testy_unjson)
print(f"REHYDRATED_JSON_DACITE {t3}")
