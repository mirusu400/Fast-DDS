import json
blob = {}

with open("/tmp/fastdds-debug", "r") as f:
    lines = f.readlines()

for line in lines:
    item, value = line.replace("\n", "").split("\t")
    if value.startswith("0x"):
        value = "[Object]"
    if item not in blob:
        # called_set = {}
        
        blob[item] = {
            "item": item,
            "called": 1,
            "return_values": {
                value: 1
            }
        }
    else:
        elem = blob[item]
        if value not in elem["return_values"]:
            elem["return_values"][value] = 1
        else:
            elem["return_values"][value] += 1
        elem["called"] += 1

with open("/tmp/fastdds-debug.json", "w") as f:
    json.dump(blob, f, indent=4)