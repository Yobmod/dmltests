class RaceCar:
    def __init__(self, color: str, fuel_remaining: float, **kwargs: int) -> None:
        self.color = color
        self.fuel_remaining = fuel_remaining

        # get laps if it is in kwargs, else set it to 0
        self.laps = kwargs.get('laps', 0)

        if 'parps' in kwargs:
            self.parps = kwargs['parps']

        # fill in any other attrs rom kwargs
        for key, value in kwargs.items():
            setattr(self, key, value)

    def run_lap(self, length: int) -> None:
        self.laps += 1
        self.fuel_remaining -= (length * 0.125)


rc = RaceCar('yellow', 31.34)
print(rc.fuel_remaining)
print(rc.laps)

rc.run_lap(6)
print(rc.fuel_remaining)
print(rc.laps)
