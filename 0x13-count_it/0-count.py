#!/usr/bin/python3
'''
    Module that queries reddit API hot articles and prints number of times
    keyword is present in title (case-insensitive, delimited by spaces.

    Example:
        Javascript should count as javascript, but java should not)
    Usage:
        python3 count_it.py <subreddit> <keyword>
'''

from collections import OrderedDict
import requests


def count_words(subreddit, word_list, after=None, word_dict={}, flag=0):
    """
        Method that recursively queries reddit API for hot articles printing
        the number of times each given keyword is present.
    """
    word_dict = OrderedDict(word_dict)
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)

    ''' page through listings'''
    headers = {"User-Agent": "Meow"}
    parameter = {'limit': 100, 'after': after}
    try:
        response = requests.get(
            url,
            headers=headers,
            params=parameter,
            allow_redirects=False)
    except BaseException:
        return(None)

    if response.status_code != 200:
        return(None)
    try:
        response = response.json()
        meow = response.get('data')
        children = meow.get('children')
        after = meow.get('after')
    except BaseException:
        return(None)

    # print(meow.get('children')[0].get('data')['title'])

    for titles in children:
        title = (titles.get('data')['title']).lower()
        for words in title.split():
            for word in word_list:
                if words == word.lower():
                    if word.lower() in word_dict.keys():
                        word_dict[word.lower()] += 1
                    else:
                        word_dict[word.lower()] = 1

    if after:
        return(count_words(subreddit, word_list, after, word_dict, flag))
    else:

        '''
            If you construct a dictionary with the words as keys and the number
            of occurrences of each word as value, simplified here as:
                d = defaultdict(int)
                for w in text.split():
                    d[w] += 1
            then you can get a list of the words, ordered by frequency of use
            with sorted(d, key=d.get) - the sort iterates over the dictionary
            keys, using the number of word occurrences as a sort key
        '''
        for x in sorted(word_dict, key=word_dict.get, reverse=True):
            print('{}: {}'.format(x, word_dict[x]))
