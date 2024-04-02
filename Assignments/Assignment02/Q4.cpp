#include <iostream>
#include <string>

using namespace std;



size_t customHash(const string& password) {
    size_t hash = 0;
    for (char ch : password) {
        hash = hash * 31 + ch; // hashing logic
    }
    return hash;
}

class Post;

class User {
protected:
    string username;
    string email;
    size_t hashedPassword; 

public:
    User(const string& username, const string& email, const string& password)
        : username(username), email(email), hashedPassword(customHash(password)) {}

  
    bool verifyUser(const string& inputPassword) {
      
        return hashedPassword == customHash(inputPassword);
    }
};


class Post {
private:
    static int nextPostId;
    int postId;
    string content;
    int likes;
    int comments;
    int views;

public:
    Post(const string& content) 
        : postId(nextPostId++), content(content), likes(0), comments(0), views(0) {}

    
    void addComment() {
        comments++;
    }

   
    void like() {
        likes++;
    }

   
    void increaseViews(int amount) {
        views += amount;
    }

  
    void increaseLikes(int amount) {
        likes += amount;
    }

   
    void display() {
        cout << "Post ID: " << postId << endl;
        cout << "Content: " << content << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
        cout << "Views: " << views << endl << endl;
    }
};

class RegularUser : public User {
private:
    static const int MAX_POSTS = 5;
    Post* feed[MAX_POSTS];
    int postCount;

public:
    RegularUser(const string& username, const string& email, const string& password) 
        : User(username, email, password), postCount(0) {}

  
    void addToFeed(Post* post) {
        if (postCount < MAX_POSTS) {
            feed[postCount++] = post;
        } else {
            cout << "Cannot add more posts to feed. Limit reached." << endl;
        }
    }

    
    void viewFeed() {
        cout << "Feed for " << username << ":" << endl;
        for (int i = 0; i < postCount; ++i) {
            feed[i]->display();
        }
    }
};

class BusinessUser : public User {
private:
    static const int MAX_PROMOTION = 10;
    int promotionCount;

public:
    BusinessUser(const string& username, const string& email, const string& password)
        : User(username, email, password), promotionCount(0) {}

   
    void promotePost(Post* post) {
        if (promotionCount < MAX_PROMOTION) {
         
            post->increaseLikes(2);
            post->increaseViews(3);
            promotionCount++;
        } else {
            cout << "Cannot promote more posts. Limit reached." << endl;
        }
    }
};



int Post::nextPostId = 1;

int main() {
 
    RegularUser regularUser("Emaan", "emaan@gmail.com", "password123");
    BusinessUser businessUser("Afnan", "afnan@gmail.com", "password456");

   
    Post post1("Summer Holidays");
    Post post2("Iftar Recipes");

 Post post3("Winter Holidays");
    Post post4("Buisness Interviews");
   
    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);
    regularUser.viewFeed();

    
   
 
    cout <<"Before promotion\n";
     post3.display();
 post4.display();
    businessUser.promotePost(&post3);
    businessUser.promotePost(&post4);

     cout <<"After promotion\n";
 post3.display();
 post4.display();
 
    return 0;
}
