from typing import List

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        total_units = 0

        for boxes, units in boxTypes:
            take = min(truckSize, boxes)
            total_units += take * units
            truckSize -= take
            if truckSize == 0:
                break

        return total_units