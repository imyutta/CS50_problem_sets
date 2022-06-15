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
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // add each pair
    // update global variable pair_count to be the total number of pairs
    int pair_array_index = 0;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_array_index].winner = i;
                pairs[pair_array_index].loser = j;
                pair_count++;
                pair_array_index++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_array_index].winner = j;
                pairs[pair_array_index].loser = i;
                pair_count++;
                pair_array_index++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int current_winner;
    int current_loser;
    int index_for_replacement;
    int max_score;
    for (int i = 0; i < pair_count - 1; i++)
    {
        max_score = preferences[pairs[i].winner][pairs[i].loser];
        current_winner = pairs[i].winner;
        current_loser = pairs[i].loser;
        index_for_replacement = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            if (max_score < preferences[pairs[j].winner][pairs[j].loser])
            {
                max_score = preferences[pairs[j].winner][pairs[j].loser];
                current_winner = pairs[j].winner;
                current_loser = pairs[j].loser;
                index_for_replacement = j;
            }
        }
        pairs[index_for_replacement].winner = pairs[i].winner;
        pairs[index_for_replacement].loser = pairs[i].loser;
        pairs[i].winner = current_winner;
        pairs[i].loser = current_loser;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // update locked to create graph by adding all adges
    for (int i = 0; i < pait_count; i++)
    {
        if (isItCycle(pairs[i].winner, pairs[i].loser) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;

    // int beaten[candidate_count];
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     beaten[i] = 0;
    // }
    // for (int i = 0; i < pair_count; i++)
    // {
    //     beaten[pairs[i].loser] = 1;
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         if (beaten[j] == 0)
    //         {
    //             locked[pairs[i].winner][pairs[i].loser] = true;
    //             break;
    //         }
    //         beaten[pairs[i].loser] = 0;
    //     }
    // }
    // return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int current_winner;
    for (int j = 0; j < candidate_count; j++)
    {
        current_winner = j;
        for ( int i = 0; i < candidate_count; i++)
        {
            if ( locked[i][j] == true)
            {
                break;
            }
            printf("%s\n", candidates[j]);
            return;
        }
    }

}

//check if a cycle appears
bool isItCycle (int from_candidate, int to_candidate)
{
    // who already beated the 'from_candidate'?
    // is there 'to_candidate'?
    //if yes
    return true;

    // if no
    // find the first one who beated the 'from_candidate'
    //was he beated by the 'to_candidate'?
    //if yes
    return true;

    //if no
    // 
    return false;
}