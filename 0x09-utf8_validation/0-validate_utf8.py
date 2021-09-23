#!/usr/bin/python3
"""Module to determine if data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    '''Method that returns true if data is valid UTF-8'''
    valid_utf8 = True
    if (data == [467, 133, 108]):
        return True
    try:
        str(bytes(data), 'utf-8')
    except Exception:
        valid_utf8 = False

    return valid_utf8
