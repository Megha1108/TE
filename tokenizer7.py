
import nltk
nltk.download("all")

from nltk.tokenize import WhitespaceTokenizer
from nltk.tokenize import WordPunctTokenizer
from nltk.tokenize import TreebankWordTokenizer
from nltk.tokenize import TweetTokenizer
from nltk.tokenize import MWETokenizer

text="Don't you love 🤗 Transformers? We sure do."

#white space
print(WhitespaceTokenizer().tokenize(text))

#Punctuation based
print(WordPunctTokenizer().tokenize(text))

#treebank
print(TreebankWordTokenizer().tokenize(text))

#tweet
print(TweetTokenizer().tokenize(text))

#multiword
print(MWETokenizer().tokenize(text))
