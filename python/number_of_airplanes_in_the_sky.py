"""
Definition of Interval.
"""
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution:
    """
    @param airplanes: An interval array
    @return: Count of airplanes are in the sky.
    """
    def countOfAirplanes(self, airplanes):
        # write your code here
        points = []
        for ap in airplanes:
            points.append([ap.start, 1])
            points.append([ap.end, -1])
            
        res, tmp= 0, 0
        for coord, val in sorted(points) :
            tmp += val
            res = max(res, tmp)
        return res

test = Solution()
airplanes =[]
airplanes.append(Interval(1,10))
airplanes.append(Interval(2,3))
res = test.countOfAirplanes(airplanes)
print(res)

