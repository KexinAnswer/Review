void Locate(ListNode* head,int x){
	if(head->RLink == head){
		return;
	}
	ListNode* cur = head->RLink;
	while(cur != head){
		
		if(cur->val == x){
			Visit(cur);
			cur->Freq++;
			break;
		} 
		cur = cur->RLink;
	}
	if(cur->LLink->Freq >= cur->Freq){
		return;
	}
	ListNode* node = cur;
	while(cur != head && cur->Freq < node->Freq){
		cur = cur->LLink;
	}
	// 从 node 的原有位置 删除
	ListNode* Npre = node->LLink;
	ListNode* Nnext = node->RLink;
	Npre->RLink = Nnext;
	Nnext->LLink = Npre;
	
	// 插入 node 的新位置
	cur->RLink->LLink = node;
	node->RLink = cur->RLink;
	node->LLink = cur;
	cur->RLink = node;
	
}


struct reference {
	int x;
	int y;
};

void ChangeZero(int arr[5][5], int m, int n) {
	std::vector<reference> pos;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] <= 0) {
				reference r;
				r.x = i;
				r.y = j;
				pos.push_back(r);
			}
		}
	}

	for (int i = 0; i < pos.size(); ++i) {
		for (int j = 0; j < m; ++j) {
			arr[j][pos[i].y] = 0;
		}
		for (int j = 0; j < n; ++j) {
			arr[pos[i].x][j] = 0;
		}
	}
}


void PreOrder(BiTree T) {
	BiTree Stack[maxsize];
	int level = 0;
	int top = -1;
	BiTree p = T;
	while (p || top >= 0) {
		while (p) {
			top++;
			level++;
			printf("%d level -> %c\n", level, p->val);
			Stack[top] = p;
			p = p->left;
		}
		p = Stack[top];
		top--;
		if (p->right == NULL) {
			level--;
		}
		p = p->right;
	}
}
