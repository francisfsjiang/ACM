Best_First_Search()
{
                   Open = [��ʼ�ڵ�];
                   Closed = [];
                   while (Open��ǿ�)
                   {
                         ��Open��ȡ��һ���ڵ�X������OPEN����ɾ����
                         if (X��Ŀ��ڵ�)
                         {
                                         ���·��PATH��
                                         ����·��PATH��
                         }
                         for (ÿһ��X���ӽڵ�Y)
                         {
                             if (Y����OPEN���CLOSE����)
                             {
                                                        ��Y�Ĺ���ֵ��
                                                        ����Y����OPEN���У�
                             }
                             //��û������
                             else if (Y��OPEN����)
                             {
                                  if (Y�Ĺ���ֵС��OPEN��Ĺ���ֵ)����OPEN���еĹ���ֵ��
                             }
                             else //Y��CLOSE����
                             {
                                  if (Y�Ĺ���ֵС��CLOSE��Ĺ���ֵ)
                                  {
                                                                   ����CLOSE���еĹ���ֵ��
                                                                   ��CLOSE�����Ƴ��ڵ㣬������OPEN���У�
                                  }
                             }
                         ��X�ڵ����CLOSE���У�
                         ���չ���ֵ��OPEN���еĽڵ�����
                         }//end for
                   }//end while
}//end func
