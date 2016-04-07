--LOADING DATA --------------------------------------------------------------------------------
lines = LOAD '/dataset/abstracts/abstract.txt' AS (line: chararray);

--Breaking strings into words -----------------------------------------------------------------
words = FOREACH lines GENERATE FLATTEN(TOKENIZE(UPPER(line))) as word;

-- Identifying dimensions -------------------------------------------------------------
heuristics = FILTER words BY (word matches '.* HEURISTIC.*') OR (word matches '.* OPTIMIZATION.*');
graphs = FILTER words BY (word matches '.* GRAPH.*') OR (word matches '.* PLANNING.*'); 
genetic_algo = FILTER words BY (word matches '.* GENETIC ALGORITHM.*') OR (word matches '.* GENETIC PROGRAMMING.*'); 
formal = FILTER words BY (word matches '.* FORMAL METHOD.*');                             
automata = FILTER words BY (word matches '.* AUTOMATA.*'); 
petri_nets = FILTER words BY (word matches '.* PETRI NET.*');                            
agents = FILTER words BY (word matches '.* AGENT.*');
/* P.S.: We aren't using an space after each word on the match because
		 they can be on plural, or have some special caracter like (',', '.', ';', etc). */
         
-- Grouping facets by words -------------------------------------------------------------------
grp_heuristics = GROUP heuristics BY word;
grp_graphs = GROUP graphs BY word;
grp_genetic = GROUP genetic_algo BY word;
grp_formal = GROUP formal BY word;
grp_automata = GROUP automata BY word;
grp_petri = GROUP petri_nets BY word;
grp_agents = GROUP agents BY word;

-- Generating groups by dimension and counting each one ---------------------------------------  
quant_heuristics = FOREACH grp_heuristics GENERATE group, COUNT(heuristics) as sum_;
quant_graphs = FOREACH grp_graphs GENERATE group, COUNT(graphs) as sum_;
quant_genetic = FOREACH grp_genetic GENERATE group, COUNT(genetic_algo) as sum_;
quant_formal = FOREACH grp_formal GENERATE group, COUNT(formal) as sum_;
quant_automata = FOREACH grp_automata GENERATE group, COUNT(automata) as sum_;
quant_petri = FOREACH grp_petri GENERATE group, COUNT(petri_nets) as sum_;
quant_agents = FOREACH grp_agents GENERATE group, COUNT(agents) as sum_;

-- Sorting aliases ----------------------------------------------------------------------------
quant_heuristics_sorted = ORDER quant_heuristics BY sum_ DESC;
quant_graphs_sorted = ORDER quant_graphs BY sum_ DESC;
quant_genetic_sorted = ORDER quant_genetic BY sum_ DESC;
quant_formal_sorted = ORDER quant_formal BY sum_ DESC;
quant_automata_sorted = ORDER quant_automata BY sum_ DESC;
quant_petri_sorted = ORDER quant_petri BY sum_ DESC;
quant_agents_sorted = ORDER quant_agents BY sum_ DESC;

-- store or dump ------------------------------------------------------------------------------
                        
