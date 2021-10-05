def find_it(array):
    return [x for x in array if array.count(x) % 2][0]


array = [20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5]#[randint(0, 5) for i in range(20)]

print(find_it(array))