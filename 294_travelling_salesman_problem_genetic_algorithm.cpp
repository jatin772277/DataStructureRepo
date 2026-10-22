#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int N;
vector<vector<double>> dist;
const int POP_SIZE = 200;
const int GENERATIONS = 2000;
const int MUT_RATE = 20;
const int TOURNAMENT = 5;
const int ELITE = 4;

struct Individual{
    vector<int> tour;
    double cost;
};

double tourCost(vector<int> t){
    double c = 0;
    for(int i = 0; i < N; i++) c += dist[t[i]][t[(i + 1) % N]];
    return c;
}

Individual randomIndividual() {
    Individual ind;
    for(int i = 0;i < N;i++) ind.tour.push_back(i);
    for(int i = N - 1;i > 0; i--){
        int j = rand() % (i + 1);
        swap(ind.tour[i],ind.tour[j]);
    }
    ind.cost = tourCost(ind.tour);
    return ind;
}

bool compareCost(Individual x, Individual y) {
    return x.cost < y.cost;
}

Individual selectParent(vector<Individual>& pop) {
    int best = rand() % POP_SIZE;
    for(int i = 1; i < TOURNAMENT; i++){
        int r = rand() % POP_SIZE;
        if (pop[r].cost < pop[best].cost) best = r;
    }
    return pop[best];
}

vector<int> crossover(vector<int>& p1, vector<int>& p2) {
    int a = rand() % N, b = rand() % N;
    if(a > b) swap(a, b);
    vector<int> child(N,-1);
    vector<bool> used(N,false);
    for(int i = a;i <= b; i++){
        child[i] = p1[i];
        used[p1[i]] = true;
    }
    int pos = (b + 1) % N;
    for(int k = 0;k < N; k++){
        int city = p2[(b + 1 + k) % N];
        if(!used[city]){
            child[pos] = city;
            used[city] = true;
            pos = (pos + 1) % N;
        }
    }
    return child;
}

void mutate(vector<int>& t) {
    if (rand() % 100 >= MUT_RATE) return;
    int a = rand() % N, b = rand() % N;
    if (a > b) swap(a, b);
    while (a < b) {
        swap(t[a], t[b]);
        a++;
        b--;
    }
}

int main() {
    srand(time(0));
    cout<<"Enter number of cities,there will be random cities: ";
    int choice;
    cin>>choice;

    if(choice <= 50){
        cout << "Need more than 50 cities.\n";
        return 0;
    }

    vector<double> x,y;
    N = choice;
    for(int i = 0; i < N; i++){
        x.push_back(rand() % 1000);
        y.push_back(rand() % 1000);
    }
    
    dist.assign(N, vector<double>(N));
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            double dx = x[i] - x[j], dy = y[i] - y[j];
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    vector<Individual> pop;
    for(int i = 0; i < POP_SIZE; i++) pop.push_back(randomIndividual());
    for(int gen = 1; gen <= GENERATIONS; gen++) {
        sort(pop.begin(), pop.end(), compareCost);
        vector<Individual> next;
        for (int i = 0; i < ELITE; i++) next.push_back(pop[i]);

        while (next.size() < POP_SIZE) {
            Individual p1 = selectParent(pop);
            Individual p2 = selectParent(pop);
            Individual child;
            child.tour = crossover(p1.tour, p2.tour);
            mutate(child.tour);
            child.cost = tourCost(child.tour);
            next.push_back(child);
        }
        pop = next;

        if (gen % 200 == 0) {
            sort(pop.begin(), pop.end(), compareCost);
            cout << "Generation " << gen << "  Best distance: " << pop[0].cost << "\n";
        }
    }

    sort(pop.begin(), pop.end(), compareCost);
    Individual best = pop[0];
    cout << "\nBest tour found:\n";
    for (int i = 0; i < N; i++) cout << best.tour[i] << " -> ";
    cout << best.tour[0] << "\n";
    cout << "Total distance: " << best.cost << "\n";
    return 0;
}