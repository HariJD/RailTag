FARE_TABLE = {
    ("StationA", "StationB"): 10,
    ("StationA", "StationC"): 20,
    ("StationB", "StationC"): 15
}

def calculate_fare(src, dest):
    return FARE_TABLE.get((src, dest), 12)
