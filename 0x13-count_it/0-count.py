#!/usr/bin/python3
import praw


def count_words(subreddit, word_list, results=None):
    if results is None:
        results = {}

    reddit = praw.Reddit(
        client_id='YOUR_CLIENT_ID',
        client_secret='YOUR_CLIENT_SECRET',
        user_agent='YOUR_USER_AGENT'
    )

    try:
        subreddit = reddit.subreddit(subreddit)
        hot_articles = subreddit.hot(limit=10)
    except Exception:
        return

    for article in hot_articles:
        title = article.title.lower()

        for word in word_list:
            word = word.lower()

            if word.endswith(('.', '!', '_')):
                continue

            count = title.count(word)

            if count > 0:
                results[word] = results.get(word, 0) + count

    if not results:
        return

    sorted_results = sorted(
        results.items(),
        key=lambda x: (-x[1], x[0])
    )

    for word, count in sorted_results:
        print(f"{word}: {count}")
