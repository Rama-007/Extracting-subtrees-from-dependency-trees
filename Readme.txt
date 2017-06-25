Number of lines should be less than 210 for cummulative.cpp where as it can be upto 5000 for get_grammar.cpp
Input is of format first number of lines followed by number of words in each sentence and then input in the github form UD_Hindi dependencies

level0[i] gives the pos tags, chunk tags , realtion between leaves and their parent nodes where as levelh[i] gives relation between a node and subtree which is not a leaf .

level0[i] is done for 3000 sentences and output is in level0grammerout.txt and nonlevel0grammer out contains the output of 400 sentences and all the subtrees are extracted using subtree_extract.cpp for 3000 sentences are listed in subtrees.txt 

if not followed this input format then would lead in segfaults . 

And dataset finalout is attached from which sentences are read