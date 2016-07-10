--These tests used the sample data provided here: http://docs.pgrouting.org/2.2/en/doc/src/developer/sampledata.html#sampledata


--Calculates the max flow from sources #2, #5, #10 to sinks #4, #9, #12.
SELECT * FROM pgr_maxflowboykovkolmogorov(
    'SELECT id,
            source,
            target,
            c1.capacity as capacity,
            c2.capacity as reverse_capacity
    FROM edge_table AS edges, category as c1, category as c2
    WHERE edges.category = c1.category AND edges.reverse_category = c2.category'
    , ARRAY[2,5,10]::INTEGER[], ARRAY[4,9,12]::INTEGER[]
);
