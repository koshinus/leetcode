#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>

#include "support_func.hpp"

class Trie_
{
    using TrieLevel = std::map<char, bool>;
    std::vector<TrieLevel> m_levels;

    bool contains(const std::string& word, bool with_additional_check)
    {
        if (word.size() > m_levels.size())
            return false;
        for (int i = 0; i < word.size(); i++)
        {
            auto& lvl = m_levels[i];
            auto lvl_it = lvl.find(word[i]);
            if (lvl_it == lvl.end())
                return false;
            if (with_additional_check && i == word.size() - 1)
                return lvl_it->second;
        }
        return true;
    }

public:
    Trie_()
    {
    }

    void insert(std::string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            bool finished_symbol = (i == word.size() - 1);
            if (m_levels.size() == i)
                m_levels.push_back(TrieLevel{});
            auto& lvl = m_levels[i];
            auto lvl_it = lvl.find(word[i]);
            if (lvl_it == lvl.end())
                lvl.insert({ word[i], finished_symbol });
            else if (finished_symbol)
            {
                std::cout << "Changing '" << lvl_it->first << "' symbol"
                    << " for word " << word << " i=" << i << "\n";
                lvl_it->second = true;
            }
        }
    }

    bool search(std::string word)
    {
        return contains(word, true);
    }

    bool startsWith(std::string prefix)
    {
        return contains(prefix, false);
    }
};

class Trie
{
    struct TrieNode
    {
        std::vector<TrieNode*> leafs;
        char c;
        bool finished;
    };

    std::vector<TrieNode> m_nodes;
    std::map<char, TrieNode*> m_roots;

    TrieNode* getNextNode(TrieNode* node, char c)
    {
        for (auto& leaf_ptr : node->leafs)
        {
            if (leaf_ptr->c == c)
                return leaf_ptr;
        }
        return nullptr;
    }

    TrieNode* traverseFromRoot(const std::string& word)
    {
        auto root_it = m_roots.find(word.front());
        if (root_it == m_roots.end())
            return nullptr;
        auto root = root_it->second;
        int i = 1;
        do
        {
            root = getNextNode(root, word[i]);
            i++;
        } while (root && i < word.size());
        return root;
    }

    TrieNode* getOrCreateRoot(char c)
    {
        auto root_it = m_roots.find(c);
        if (root_it != m_roots.end())
            return root_it->second;
        m_nodes.push_back(TrieNode{ {}, c, false });
        m_roots[c] = &m_nodes.back();
        return &m_nodes.back();
    }
public:
    Trie() {}

    void insert(std::string word)
    {
        TrieNode* root = getOrCreateRoot(word[0]), * next_node = nullptr;
        int i = 1;
        do
        {
            std::cout << "1\n";
            next_node = getNextNode(root, word[i]);
            if (!next_node)
            {
                std::cout << "3\n";
                // m_nodes.push_back( TrieNode{ {}, word[i], i == word.size() - 1 } );
                // root->leafs.push_back( &m_nodes.back() );
                // next_node = &m_nodes.back();
            }
            // root = next_node;
            i++;
        } while (i < word.size());
        if (root)
            root->finished = true;
    }

    bool search(std::string word)
    {
        auto leaf_ptr = traverseFromRoot(word);
        return leaf_ptr && leaf_ptr->finished;
    }

    bool startsWith(std::string prefix)
    {
        auto leaf_ptr = traverseFromRoot(prefix);
        return leaf_ptr;
    }
};


namespace trie_implementation
{
    void test1()
    {
        Trie t;
        t.insert("app");
        // t.insert("apple");
        // t.insert("beer");
        // t.insert("jam");
        // t.insert("rental");
        // t.insert("apps");

        std::cout << t.search("app") << " ";
        std::cout << t.search("ad") << " ";
        std::cout << t.search("applepie") << " ";
        std::cout << t.search("rest") << " ";
        std::cout << t.search("jan") << " ";
        std::cout << t.search("rent") << " ";
        std::cout << t.search("beer") << " ";
        std::cout << t.search("jam") << " ";
        std::cout << t.search("apps") << " ";

        std::cout << t.startsWith("app") << " ";
        std::cout << t.startsWith("ad") << " ";
        std::cout << t.startsWith("applepie") << " ";
        std::cout << t.startsWith("rest") << " ";
        std::cout << t.startsWith("jan") << " ";
        std::cout << t.startsWith("rent") << " ";
        std::cout << t.startsWith("beer") << " ";
        std::cout << t.startsWith("jam") << " ";

        //["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],
        //["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]
    }

    void test2()
    {
    }
    
    void run_tests()
    {
        test1();
        test2();
    }
}