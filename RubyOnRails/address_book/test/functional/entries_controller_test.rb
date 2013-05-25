require 'test_helper'

class EntriesControllerTest < ActionController::TestCase
  setup do
    @entry = entries(:valid)
    @update = {
      first_name:	'John',
      last_name:	'Doe'
    }
    @search = "richard"
  end

  test "should get index" do
    get :index
    assert_response :success #get back a HTTP 200 code, not 404
    assert_not_nil assigns(:entries) #check that getting an entry
  end

  test "should get new" do
    get :new 
    assert_response :success
  end

  test "should have all fields in form" do
    get :new
    accessible_attrs(Entry).each do |f|
      assert_select "input#entry_#{f}", true
    end
  end

  test "should create entry" do
    assert_difference('Entry.count') do
      post :create, entry: @update
    end

    assert_redirected_to entry_path(assigns(:entry))
  end

  test "should show entry" do
    get :show, id: @entry
    assert_response :success
  end

  test "should get edit" do
    get :edit, id: @entry
    assert_response :success
  end

  test "should have all input filled in edit form" do
    get :edit, id: @entry
    accessible_attrs(Entry).each do |f|
    	if f != "avatar" && f != "avatar_cache"
	      assert_select "input#entry_#{f}[value=?]", @entry.send(f)
	    end
    end
  end

  test "should update entry" do
    put :update, id: @entry, entry: @update
    assert_redirected_to entry_path(assigns(:entry))
  end

  test "should destroy entry" do
    assert_difference('Entry.count', -1) do
      delete :destroy, id: @entry
    end

    assert_redirected_to entries_path
  end
   
end
