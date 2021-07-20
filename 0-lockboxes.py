#!/usr/bin/python3
'''This Module counts determines if there are adequate keys to open n-1 boxes'''

def canUnlockAll(boxes):
    '''Method to return True or False if all boxes could be opened
       Return: True if all boxes can be opened. Else False.
    '''
    haveKeys = [0]
    totalBoxes = len(boxes)
    totalKeys = len(haveKeys)

    for key in haveKeys:
        #print(key)-> 0
        #print(len(haveKeys)) -> 1
        # print(boxes[key])
        for keys in boxes[key]:
            #print(keys) -> 1
            if (keys not in haveKeys) and (keys < totalBoxes):
                haveKeys.append(keys)
    if (len(haveKeys) == totalBoxes):
        return True
    else:
        return False
                #print(haveKeys)->[0, 1, 2, 3, 4]
            #print(index, keys) #-> 0 [1], 1 [2], 2 [3], 3 [4], 4 []
        
    #     if (keys not in haveKeys) and (keys < boxTotal)
    #     if index == 0:
    #         unlockedBox[index + 1] = False
    #     else:
    #         unlockedBox[index + 1] = True

    # #print(unlockedBox)->{1: False, 2: True, 3: True, 4: True, 5: True}
    # for key, val in unlockedBox.items():
    #     if key in haveKeys:
    #         if (heldKey == key) and (val == True):
    #             unlockedBox[key] = False
    #         else:
    #             unlockedBox[key] = True

        # print(key) -> (1,2,3,4,5)
    #print(unlockedBox)#-->(dict_items([(1, False), (2, True), (3, True), (4, True), (5, True)]))
    #     if (unlockedBox.keys() == True):
    #         unlockedBox[key] = False
    # print(unlockedBox)


    # for key in haveKeys:
    #     if (key < len(boxes)) and (lockBox[key] != True):
    #         lockBox[key] = True
    #     for vals in lockBox.values():
    #         print (vals)


        
    # print("Box = {}, haveKeys = {}".format(box, haveKeys))
    #     for keys in haveKeys:
    #         if keys < len(boxes):
    #         # print(box, haveKeys)
    #             openDict[box + 1] = True
                
    #         else:
    #             openDict[box + 1] = False
                
    #     print(openDict)

    
    # # if False in openDict.values():
    # #     return (False)
    # # else:
    # #     return (True)


        
            # print("Box #{} contains:{}".format(box, box_key))
