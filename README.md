Assumptions made:

    * Has to convert data in streaming fashion
    * Logical data packets can come in chunks, thus DataIntegrators are introduced
        (but for csv and tsv when reading by line no integration required)
    * Logical packets can be transformed to another format one by one
        (no knowledge of next packet is needed for current packet transformation)

File reading loop is run in transformer.cpp

    * First it tries to get input format and accumulates read data
    * Whet format aquired accumulated data passed into data integrator
        to check (in pottential implementation) for logical consistency
    * Then data transformed using Format Transformers
    * And then written to file.


to build run 'make transformer'

to run csv to tsv conversion './transformer ./input_csv_3 ./out.tsv' 

to run conversion back       './transformer ./out.tsv ./out.csv'
