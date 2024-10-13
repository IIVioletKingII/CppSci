ut << std::endl;

	LLInt.deleteByValue(300);

	for( int i = 0; i < LLInt.getSize( ); ++i ) {
		std::cout << LLInt.getByIndex(i) << std::endl;
	}