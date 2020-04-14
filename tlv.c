
void
decode_tlv_132(char *tlv_ptr){

  int tlv_type = (int)*tlv_ptr; //reading type value
  tlv_ptr++;

  int data_length = (int)*tlv_ptr; //reading data length
  tlv_ptr++;

  int unit_tlv_size = get_unit_size(tlv_type);

  char ip_address[32];
  char mask;
  switch(tlv_type){
    case 132:
    {
      int n_units = data_length/unit_tlv_size;
      for(int i=0; i< n_units; i++){

        #if0
        //Hardware dependent copying of bytes to loacl variable.
        unsigned int ip_address = *((unsigned int*)tlv_ptr)
        #endif

        memcpy(ip_address, tlv_ptr, 4);
        tlv_ptr += 4;

        mask = *tlv_ptr;

        tlv_ptr++;
      }
    }
    break;
    default:
      tlv_ptr += data_length;
    break;
  }
}
