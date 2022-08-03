class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> g_map;
        for(size_t i = 0; i < equations.size(); i++)
        {
        // add forward edge
                auto iter = g_map.find(equations[i][0]);
                if(iter == g_map.end())
                    g_map[equations[i][0]] = unordered_map<string, double>{};
                g_map[equations[i][0]].insert({equations[i][1], values[i]});

                // add backward edge
                iter = g_map.find(equations[i][1]);
                if(iter == g_map.end())
                    g_map[equations[i][1]] = unordered_map<string, double>{};
                g_map[equations[i][1]].insert({equations[i][0], 1.0/values[i]});
        }
        for(const auto& query: queries)
        {
            double q_res = handle_a_query(query, g_map);
            res.push_back(q_res);
        }
        return res;
    }

    
    double handle_a_query(vector<string> query, unordered_map<string, unordered_map<string, double>> eq_graph){
        if(query[0] == query[1] & eq_graph.find(query[0]) != eq_graph.end()) return 1.0;
        string start = query[0];
        vector<string> nodes{start};
        vector<double> values{1.0};
        unordered_set<string> visited;

        while(!nodes.empty())
        {
            string current_node = nodes.back();
            nodes.pop_back();
            if(visited.find(current_node) != visited.end()) continue;
            visited.insert(current_node);

            double current_node_val = values.back();
            values.pop_back();

            auto iter = eq_graph.find(current_node);
            if(iter != eq_graph.end())
            {
                unordered_map<string, double> next_node = eq_graph[current_node];
                for(const pair<const string, double>& edge: next_node)
                {
                    if(visited.find(edge.first) == visited.end())
                    {
                        nodes.push_back(edge.first);
                        // if we reach the target
                        if(edge.first == query[1]) return current_node_val*edge.second;
                        values.push_back(current_node_val*edge.second);
                    }
                }
            }
        }
        return -1.0;
    }
};