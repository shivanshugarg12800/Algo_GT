def isLongPressedName(self, name: str, typed: str) -> bool:
    i = 0
    j = 0
    if (len(typed) < len(name)):
        return False

    while (i < len(name) or j < len(typed)):
        ''' this is for the condition when characters are same
            we increment the i and j '''
            
        if (i < len(name) and j < len(typed) and name[i] == typed[j]):
            i += 1
            j += 1

        # if not equal then there is possibility that typed[j] can be equal to i-1
        elif (i > 0 and j < len(typed) and name[i - 1] == typed[j]):
            j += 1

        else:
            return False

    return True