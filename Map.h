namespace seongryul
{
	inline int Map1[10][10]{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 2, 1},
	{1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
}

/*

//1�� ��

inline int Map1[10][10]{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 2, 1},
	{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

// 2�� ��

inline int Map1[10][10]{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 2, 1},
	{1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

// 3�� ��

inline int Map1[10][10]{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 2, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	// 4�� ��

inline int Map1[10][10]{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 2, 1},
	{1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

// 5 �� ��

inline int Map1[10][10]{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

*/