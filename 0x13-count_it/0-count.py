#!/usr/bin/python3
'''
    Module that queries reddit API hot articles and prints number of times
    keyword is present in title (case-insensitive, delimited by spaces.

    Example:
        Javascript should count as javascript, but java should not)
    Usage:
        python3 count_it.py <subreddit> <keyword>
'''

import requests


def count_words(subreddit, word_list, after=None, word_dict={}, flag=0):
    """
        Method that recursively queries reddit API for hot articles printing
        the number of times each given keyword is present.
    """

    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)

    ''' page through listings'''
    parameter = {'limit': 100, 'after': after}
    headers = {"User-Agent": "Meow"}
    response = requests.get(
        url,
        headers=headers,
        params=parameter,
        allow_redirects=False)
    if response.status_code != 200:
        return(None)
    response = response.json()
    meow = response.get('data')
    children = meow.get('children')
    after = meow.get('after')
    for titles in children:
        title_fetch = titles.get('data')['title'].lower()
        # print(title_fetch)
        for word in word_list:
            if word in title_fetch:
                flag += 1
                word_dict[word] = flag
    if after is None:
        for x in word_dict.keys():
            print("{}: {}".format(x, word_dict[x]))
        return
    return(count_words(subreddit, word_list, after, word_dict, flag))
