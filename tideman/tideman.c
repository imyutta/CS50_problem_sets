#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool isItCycle (int from_candidate, int to_candidate);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }
    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // look for a candidate called NAME
    // if found, update ranks and return true.
    // if not found, return false
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int winner = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            int looser = ranks[j];
            preferences[winner][looser] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // add each pair
    // update global variable pair_count to be the total number of pairs
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair current;
    int index_for_replacement;
    int max_score;
    for (int i = 0; i < pair_count - 1; i++)
    {
        max_score = preferences[pairs[i].winner][pairs[i].loser];
        current = pairs[i];
        index_for_replacement = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            if (max_score < preferences[pairs[j].winner][pairs[j].loser])
            {
                max_score = preferences[pairs[j].winner][pairs[j].loser];
                current = pairs[j];
                index_for_replacement = j;
            }
        }
        pairs[index_for_replacement] = pairs[i];
        pairs[i] = current;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // update locked to create graph by adding all adges
    for (int i = 0; i < pair_count; i++)
    {
        if (isItCycle(pairs[i].winner, pairs[i].loser) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winner;
    int winner_sum = 0;
    int current_sum;

    for (int j = 0; j < candidate_count; j++)
    {
        current_sum = 0;
        for ( int i = 0; i < candidate_count; i++)
        {
            if ( locked[i][j] == true)
            {
                break;
            }

            for (int pref = 0; pref < candidate_count; pref++)
            {
                current_sum += preferences[j][pref];
            }
            if (current_sum > winner_sum)
            {
                winner = j;
                winner_sum = current_sum;
            }
        }
    }
    printf("%s\n", candidates[winner]);
    return;
}

//check if a cycle appears
bool isItCycle (int from_candidate, int to_candidate)
{

    // find those who already beated the 'from_candidate'
    // is there 'to_candidate'?
    if (locked[to_candidate][from_candidate] == true)
    {
        return true;
    }

    // then, who already beated the 'from_candidate'?
    for (int i= 0; i < candidate_count; i++)
    {

        if (locked[i][from_candidate] == true && isItCycle(i, to_candidate) == true)
        {
            return true;
        }
    }
    return false;
}