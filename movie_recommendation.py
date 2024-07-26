import numpy as np 
import pandas as pd 
import difflib
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import TfidfVectorizer 
import cosine_similarity 
import os
import tkinter as tk
from tkinter import messagebox

# Read movies data
movies_data = pd.read_csv('movies.csv')

# Replace null values with empty string
selected_features = ['genres', 'keywords', 'tagline', 'cast', 'director'] 
for feature in selected_features:
    movies_data[feature] = movies_data[feature].fillna('')

# Combine all selected features
combined_features = movies_data['genres'] + ' ' + movies_data['keywords'] + ' ' + movies_data['tagline'] + ' ' + movies_data['cast'] + ' ' + movies_data['director']


# Convert text data to feature vectors 
vectorizer = TfidfVectorizer()
feature_vectors = vectorizer.fit_transform(combined_features)

# Compute similarity scores using cosine similarity 
similarity = cosine_similarity(feature_vectors)

# GUI
def recommend_movies(): 
    movie_name = entry.get()

    # Creating a list with all the movie names given in the dataset 
    list_of_all_titles = movies_data['title'].tolist()

    # Finding close match for the movie name given by the user 
    find_close_match = difflib.get_close_matches(movie_name, list_of_all_titles)

    if not find_close_match: 
        messagebox.showinfo("Error", "Movie not found!") 
        return

    close_match = find_close_match[0]
    index_of_the_movie = movies_data[movies_data.title == close_match]['index'].values[0] 
    similarity_score = list(enumerate(similarity[index_of_the_movie])) 
    sorted_similar_movies = sorted(similarity_score, key=lambda x: x[1], reverse=True)[:30]

    # Display recommended movies 
    recommended_movies = ""
    for i, movie in enumerate(sorted_similar_movies, start=1): 
        index = movie[0]
        title_from_index = movies_data[movies_data.index == index]['title'].values[0] 
        recommended_movies += f"{i}. {title_from_index}\n"
    messagebox.showinfo("Movies suggested for you", recommended_movies)

# Create GUI window 
root = tk.Tk()
root.title("Movie Recommender") 
root.geometry("300x150")

label = tk.Label(root, text="Enter your favorite movie name:") 
label.pack()

entry = tk.Entry(root, width=30) 
entry.pack()

button = tk.Button(root, text="Recommend Movies", command=recommend_movies) 
button.pack()

root.mainloop()